#ifndef __PRODUCT__
#define __PRODUCT__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product
{
public:
	static vector<Product> products_vector;

	Product();
	Product(string item_name, float price);
	Product(string line);

	string get_item_name();
	float get_price();

	void set_item_name(string name);
	void set_price(float price);
	void show();

	static void load_products_to_vector();
	static vector<Product> get_products();



private:
	string item_name;
	float price;

};

#endif // !__PRODUCT__