#include "Client.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>


Client::Client()     // default constructor
{
	id = 0;
	name = "NULL";
	day = 0;
	month = 0;
	year = 0;
	spendings = 0;
}

Client::Client(unsigned int id, string name, unsigned int day, unsigned int month, unsigned int year, float spendings)
{	
	Client::id = id;
	Client::name = name;
	Client::day = day;
	Client::month = month;
	Client::year = year;
	Client::spendings = spendings;
}

Client::Client(string line)
{	
	string delimiter = " ; ";
	size_t pos = 0;
	string token;
	int i = 0;
	string store_line [3];  
	string line_copy = line;

	while ((pos = line_copy.find(delimiter)) != string::npos) 
	{

		token = line_copy.substr(0, pos);
		store_line[i] = token;
		line_copy.erase(0, pos + delimiter.length());
		i++;
	}

	string store_dates [3];
	string input = line;							// this seperates the date month etc into theyr own tokens
	istringstream ss(store_line[2]);							// using this cause getline only reads a single char
	string token1;	
	int j = 0;										// so here I could use it for the '/', whilst on the
	while (getline(ss, token1, '/'))					// one above it was 3 char (" ; ")[spaces...]
	{
		store_dates[j] = token1;
		j++;
	}

	// float cash = atof(line_copy);

	Client::id = atoi(store_line[0].c_str());								// LISTEN: PARA FAZER COM QUE A DATA SEJA SÓ UMA COISA, É SO MUDAR O COST PARA TER O Client::DATE = atoi(store_line[2].c_str());
	Client::name = store_line[1];
	Client::day = atoi(store_dates[0].c_str());
	Client::month = atoi(store_dates[1].c_str());
	Client::year = atoi(store_dates[2].c_str());
	Client::spendings = atof(line_copy.c_str());  // atof() = all to float
	
// Client new_client(stoi(line.substr(0, line.find(" ")))(), name, day, month, year, spendings);
}

int Client::get_id()
{
	return Client::id;
}

string Client::get_name()
{
	return Client::name;
}

int Client::get_day()
{
	return Client::day;
}

int Client::get_month()
{
	return Client::month;
}

int Client::get_year()
{
	return Client::year;
}

float Client::get_spendings()
{
	return Client::spendings;
}

void Client::set_id(unsigned int id)
{
	Client::id = id;                           // this-> id = id;
}

void Client::set_name(string name)
{
	Client::name = name;
}

void Client::set_day(unsigned int day)
{
	Client::day = day;
}

void Client::set_month(unsigned int month)
{
	Client::month = month;
}

void Client::set_year(unsigned int year)
{
	Client::year = year;
}

void Client::set_spendings(float spendings)
{
	Client::spendings = spendings;
}

void Client::show()
{
	cout << id << "  ;  " << name << "  ;  " << day << "/" << month << "/" << year << "  ;  " << spendings << endl;
}



void Client::write()
{
	ofstream myfile;
	myfile.open("clients_work.txt", std::ios_base::app);
	myfile << id << " ; " << name << " ; " << day << "/" << month << "/" << year << " ; " << spendings << endl;
	myfile.close();
}

void Client::edit_all()
{

}

void Client::load_clients_to_vector()
{
		cout << "Now loading all clients " << endl;
		string line;


		ifstream myfile("clients_work.txt");
		if (myfile.is_open())
		{
			myfile.ignore(1000, '\n'); //ignore the 4
			while (getline(myfile, line))						// scans every line
			{
					Client new_client(line);
					/*
					int i = 0;
					client_vector[i] = new_client;
					i++;
					*/
					clients_vector.push_back(new_client);
			}
			myfile.close();

		}

		// cout << client_vector[2].get_name() << endl;	      // test, works.

}

vector<Client> Client::get_clients()
{
	return clients_vector;
}


string Client::toString()
{
	return id + " ; " + name + " ; " + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " ; " + to_string(spendings);
}


