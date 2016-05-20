#include "Transactions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

Transaction::Transaction()
{
	id = 0;
	date = "NULL";
	products = "NULL";
}

Transaction::Transaction(int id, string date, string products)
{
	Transaction::id = id;
	Transaction::date = date;
	Transaction::products = products;
}

Transaction::Transaction(string line) // needs to skip first line ("4")
{
	string delimiter = " ; ";
	size_t pos = 0;
	string token;
	int i = 0;
	string store_line[3];
	string line_copy = line;

	while ((pos = line_copy.find(delimiter)) != string::npos)
	{
		token = line_copy.substr(0, pos);
		store_line[i] = token;
		line_copy.erase(0, pos + delimiter.length());
		i++;
	}

	Transaction::id = atoi(store_line[0].c_str());
	Transaction::date = store_line[1];
	Transaction::products = line_copy.c_str();
}

int Transaction::get_id()
{
	return Transaction::id;
}

string Transaction::get_date()
{
	return Transaction::date;
}

string Transaction::get_products()
{
	return Transaction::products;
}

void Transaction::set_id(int id)
{
	Transaction::id = id;
}

void Transaction::set_date(string date)
{
	Transaction::date = date;
}

void Transaction::set_products(string products)
{
	Transaction::products = products;
}

void Transaction::show()
{
	cout << id << "  ;  " << date << "  ;  " << products << endl;
}

void Transaction::load_transactions_to_vector()
{
	{
		cout << "Now loading all products " << endl;
		string line;


		ifstream myfile("transactions_work.txt");
		if (myfile.is_open())
		{
			myfile.ignore(1000, '\n'); //ignore the 4
			while (getline(myfile, line))						// scans every line
			{
				Transaction new_transaction(line);
				/*
				int i = 0;
				client_vector[i] = new_client;
				i++;
				*/
				transactions_vector.push_back(new_transaction);
			}
			myfile.close();

		}

		// cout << client_vector[2].get_name() << endl;	      // test, works.

	}
}

vector<Transaction> Transaction::get_transactions()
{
	return transactions_vector;
}
