#ifndef __TRANSACTION__
#define __TRANSACTION__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transaction
{
public:
	static vector<Transaction> transactions_vector;

	Transaction();
	Transaction(int id, string date, string products);
	Transaction(string line);

	int get_id();
	string get_date();
	string get_products();

	void set_id(int id);
	void set_date(string date);
	void set_products(string products);
	void show();

	static void load_transactions_to_vector();
	static vector<Transaction> get_transactions();

private:
	int id;
	string date;
	string products;

};

#endif // !__Transaction__