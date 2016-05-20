#ifndef __CLIENT__
#define __CLIENT__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Client
{
public:
	static vector<Client> clients_vector;

	Client();
	Client(unsigned int id, string name, unsigned int day, unsigned int month, unsigned int year, float spendings);
	Client(string line);

	int get_id();
	string get_name();
	int get_day();
	int get_month();
	int get_year();
	float get_spendings();

	void set_id(unsigned int id);
	void set_name(string name);
	void set_day(unsigned int day);
	void set_month(unsigned int month);
	void set_year(unsigned int year);
	void set_spendings(float spendings);
	void show();
	void write();
	void edit_all();

	static void load_clients_to_vector();
	static vector<Client> get_clients();

	// void display_all();
	


	string toString();
	
	


private:
	unsigned int id;
	string name;
	unsigned int day;
	unsigned int month;
	unsigned int year;
	float spendings;
	
};



#endif // !__CLIENT__