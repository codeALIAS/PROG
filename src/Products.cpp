#include "Products.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


Product::Product()
{
	item_name = "NULL";
	price = 0;
}

Product::Product(string item_name, float price)
{
	Product::item_name = item_name;
	Product::price = price;
}

Product::Product(string line) // tem de nput sem o 4 já
{
	string delimiter = " ; ";
	size_t pos = 0;
	string token;
	int i = 0;
	string store_line[2];
	string line_copy = line;

	while ((pos = line_copy.find(delimiter)) != string::npos)
	{
		token = line_copy.substr(0, pos);
		store_line[i] = token;
		line_copy.erase(0, pos + delimiter.length());
		i++;
	}

	Product::item_name = store_line[0];
	Product::price = atof(store_line[1].c_str());
}

string Product::get_item_name()
{
	return Product::item_name;
}

float Product::get_price()
{
	return Product::price;
}

void Product::set_item_name(string name)
{
	Product::item_name = name;
}

void Product::set_price(float price)
{
	Product::price = price;
}

void Product::show()
{
	cout << item_name << "  ;  " << price << endl;
}

void Product::load_products_to_vector()
{
	cout << "Now loading all products " << endl;
	string line;


	ifstream myfile("products_work.txt");
	if (myfile.is_open())
	{
		myfile.ignore(1000, '\n'); //ignore the 4
		while (getline(myfile, line))						// scans every line
		{
			Product new_product(line);
			/*
			int i = 0;
			client_vector[i] = new_client;
			i++;
			*/
			products_vector.push_back(new_product);
		}
		myfile.close();

	}

	// cout << client_vector[2].get_name() << endl;	      // test, works.

}

vector<Product> Product::get_products()
{
	return products_vector;
}
