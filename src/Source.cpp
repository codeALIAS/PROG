#include "Client.h"
#include "Products.h"
#include "Transactions.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>


using namespace std;

int check()												// stops program from closing
{
	int check;

	cout << "type 0 to close" << endl;
	cin >> check;

	while (cin.fail() || check != 0)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "invalid input, try again" << endl;
		cin >> check;
	}

	return 0;
}

void display_all()										// prints full .txt on screen
{
	string line;
	ifstream myfile("clients_work.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";
}

vector<Client> load_to_vector()
{
	cout << "Now loading all clients " << endl;
	
	vector<Client> client_vector;
	string line;

	
	ifstream myfile("clients_work.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))						// scans every line
		{
			if (line.substr(1,2) != "  ")// se nao for a primeira linha só com o contador
			{
				Client new_client(line);
				/* 
				int i = 0;
				client_vector[i] = new_client;
				i++;
				*/
				client_vector.push_back(new_client);
			}
		}
		myfile.close();
		
	}

	return client_vector;

// cout << client_vector[2].get_name() << endl;	      // test, works.

}
// -----------------------------------------------------------------------------------------------------





void edit_client() // void edit_client(vector<Client> vector_clients)
{
	// variables
	int in_id;

	// ask user what id of the clent to edit
	cout << "what is the id of the client to edit ? " << endl;
	cin >> in_id;

	// scan file for id
	string line;
	int current_id;
	string newfile;

	ifstream myfile("clients_work.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))						// scans every line
		{
			current_id = stoi(line.substr(0, line.find(" ")));	// untill first space   // stoy() to use the string method to search but to return in an int
			if (current_id == in_id)
			{
				Client edited_client(line);

				cout << "what should be edited ? " << endl;
				cout << "edit name [1] " << endl;
				cout << "edit day [2] " << endl;
				cout << "edit month [3] " << endl;
				cout << "edit year [4] " << endl;
				cout << "edit spendings [5] " << endl;


				int pick;
				cin >> pick;


				string name;
				unsigned int day;
				unsigned int month;
				unsigned int year;
				float spendings;

				switch (pick)
				{

				case 1:
					// system("CLS");


					cout << "new name ? " << endl;
					cin >> name;

					edited_client.set_name(name);

					break;

				case 2:
					// system("CLS");

					cout << "new day ? " << endl;
					cin >> day;

					edited_client.set_day(day);

					break;

				case 3:
					// system("CLS");

					cout << "new month ? " << endl;
					cin >> month;

					edited_client.set_month(month);

					break;

				case 4:
					// system("CLS");

					cout << "new year ? " << endl;
					cin >> year;

					edited_client.set_year(year);

					break;

				case 5:
					// system("CLS");

					cout << "new spendings ? " << endl;
					cin >> spendings;

					edited_client.set_name(name);

					break;

				default:
					cout << "incorrect input " << endl;
				}
				newfile = newfile + edited_client.toString() + "\n";
			}

			else
			{
				newfile = newfile + line + "\n";
			}
		}
		myfile.close();

		ofstream myfile_out;

		myfile_out.open("clients_work.txt");
		myfile_out << newfile;
		myfile_out.close();
	}

	else cout << "Unable to open file";

	// run the editor or run a specific editor(only name, only spendinsg, etc)

	// delete from txt using delete_client()

	// write to txt
}

// USE THIS AT CREAT CLINET

int make_id()
{
	string line;
	int max_id = 0;
	int current_id;

	ifstream myfile("clients_work.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))						// scans every line
		{
			current_id = stoi(line.substr(0, line.find(" ")));	// untill first space   // stoy() to use the string method to search but to return in an int
			if (current_id > max_id)
			{
				max_id = current_id;
			}

		}
		myfile.close();

		return ++max_id;
	}

	else cout << "Unable to open file";

	// scan document for all id's
	// take largest one and ++
	// return that int


}


void create_client_by_user()   		  	    		           // ask for client name, id, etc
{
	//variables
	string name;
	int day;
	int month;
	int year;
	float spendings;
	// ask for information
	cout << "Insert name: " << endl;
	cin >> name;
	cout << "what day is today ? : " << endl;
	cin >> day;
	cout << "Month ? : " << endl;
	cin >> month;
	cout << "Year ? " << endl;
	cin >> year;
	cout << "Current spendings ? " << endl;
	cin >> spendings;

	Client new_client(make_id(), name, day, month, year, spendings);
	new_client.write();



	//store it 

	// client.set.. with info

}

void delete_client()
{
	// pessoas com nomes iguas, logo serach por id, :^)
	// ask what id of the person to delete

	string id;
	string line;
	string newfile;

	cout << "Qual o  id do cliente a apagar ? " << endl;
	cin >> id;

	// search for it

	ifstream myfile_in("clients_work.txt");
	if (myfile_in.is_open())
	{
		while (getline(myfile_in, line))						// scans every line
		{
			if (line.substr(0, line.find(" ")) != id)
			{
				newfile = newfile + line + "\n";					// if it DID NOT found the id
			}
		}
		myfile_in.close();

		ofstream myfile_out;

		myfile_out.open("clients_work.txt");
		myfile_out << newfile;
		myfile_out.close();
	}
}
//delete whole line

/*

// --------------------------------------- INTERFACE ---------------------------------------- //
int client_screen()
{
	cout << "-------- [Client Management] --------" << endl;
	cout << "|                                    |" << endl;
	cout << "|        Create Client:  [1]         |" << endl;
	cout << "-------------------------------------" << endl;
	cout << "|                                    |" << endl;
	cout << "|         View Clients:  [2]         |" << endl;
	cout << "|                                    |" << endl;
	cout << "-------------------------------------" << endl;

	int pick;
	cin >> pick;

	switch (pick)
	{
	case 1:
		system("CLS");
		client_screen();
		break;

	case 2:
		system("CLS");
		info_screen();
		break;

	case 3:
		system("CLS");
		shopping_screen();
		break;

	case 4:
		system("CLS");
		publicity_screen();
		break;

	case 5:
		system("CLS");
		exit_screen();
		break;

	default:
		cout << "incorrect input" << endl;

	}

	return 0;
}

int info_screen()
{
	cout << "----------- [Menu Screen] -----------" << endl;
	cout << "|                                    |" << endl;
	cout << "|         CINFORMATUOIN]    |" << endl;
	return 0;
}

int shopping_screen()
{
	cout << "----------- [Menu Screen] -----------" << endl;
	cout << "|                                    |" << endl;
	cout << "|         CSHIOPPINFGt:  [1]    |" << endl;
	return 0;
}

int publicity_screen()
{
	cout << "----------- [Menu Screen] -----------" << endl;
	cout << "|                                    |" << endl;
	cout << "|         PUBLICITYt:  [1]    |" << endl;
	return 0;
}

int exit_screen()
{
	cout << "----------- [Menu Screen] -----------" << endl;
	cout << "|                                    |" << endl;
	cout << "|         BYE BYEnt:  [1]    |" << endl;
	return 0;
}

int start_menu()
{

	cout << "__      ________ _   _ _____  ______               " << endl;
	cout << "\ \    / /  ____| \ | |  __ \|  ____|    _     _   " << endl;
	cout << " \ \  / /| |__  |  \| | |  | | |__     _| |_ _| |_ " << endl;
	cout << "  \ \/ / |  __| | . ` | |  | |  __|   |_   _|_   _|" << endl;
	cout << "   \  /  | |____| |\  | |__| | |____    |_|   |_|  " << endl;
	cout << "    \/   |______|_| \_|_____/|______|              " << endl;
	cout << endl;
	cout << "by Hugo Neves << endl;




	cout << "----------- [Menu Screen] -----------" << endl;
	cout << "|                                    |" << endl;
	cout << "|         Client Management:  [1]    |" << endl;
	cout << "-------------------------------------" << endl;
	cout << "|                                    |" << endl;
	cout << "|         Information Screen: [2]    |" << endl;
	cout << "|                                    |" << endl;
	cout << "-------------------------------------" << endl;
	cout << "|              Shopping:      [3]    |" << endl;
	cout << "|                                    |" << endl;
	cout << "-------------------------------------" << endl;
	cout << "|          Custom Publicity:  [4]    |" << endl;
	cout << "|                                    |" << endl;
	cout << "-------------------------------------" << endl;
	cout << "|               Exit Menu:    [5]    |" << endl;
	cout << "|                                    |" << endl;
	cout << "-------------------------------------" << endl;

	cout << "Client management will " << endl;



	int pick;
	cin >> pick;

	switch (pick)
	{
	case 1:
		system("CLS");
		client_screen();
		break;

	case 2:
		system("CLS");
		info_screen();
		break;

	case 3:
		system("CLS");
		shopping_screen();
		break;

	case 4:
		system("CLS");
		publicity_screen();
		break;

	case 5:
		system("CLS");
		exit_screen();
		break;

	default:
		cout << "incorrect input" << endl;

	}


	return 0;
}


*/

vector <Client> Client::clients_vector = {};
vector <Product> Product::products_vector = {};
vector <Transaction> Transaction::transactions_vector = {};
int main()
{

	//--------------------------------------------------------------------------------------------------------------------------------------

	// display_all(); // works

	// edit_client(); // NOT WORKING ERROR IN YEAR AT CLIENT.H

	// create_client_by_user(); // WORKING : writing directly to txt, needs to save to vector as well

	// vector<Client> clients_vector = load_to_vector();

	// edit_client(clients_vector);


	// string test = "6 ; Joana Beires ; 15/10/2010 ; 7.50";
	// Client escumalha(test);
	



	Client::load_clients_to_vector();
	Client::get_clients()[0].show();

	Transaction::load_transactions_to_vector();
	Transaction::get_transactions()[0].show();

	Product::load_products_to_vector();
	Product::get_products()[0].show();






	//--------------------------------------------------------------------------------------------------------------------------------------

	//Client test(92, "Alberto Rui das Silvas" , 11, 9, 2001, 420.69);
	//test.set_name("cuck da vila");
	//test.show();
	//test.write();

	//display_all();
	//create_client_by_user();

	//delete_client();

	/*
	time_t  timev;
	time(&timev);

	cout << timev << endl;
	*/

	//	cout << make_id() << endl;
	check();

	return 0;
}