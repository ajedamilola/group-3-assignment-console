// group-6-assignment-console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Shop.h"
#include "Item.h"
#include <vector>
#include <limits> 

using namespace std;

//Insert value is a overloaded function thwse are helper functions 
void insertValue(string message, string& value, bool succeedsNumericValue = false) {
	cout << message;
	if (succeedsNumericValue) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	getline(cin, value);
}
void insertValue(string message, float& value) {
	cout << message;
	cin >> value;
}
void insertValue(string message, int& value) {
	cout << message;
	cin >> value;
}

void print(string message) {
	cout << message << "\n";
}

int main()
{
	//creating our shop
	Shop shop = Shop();

	print("===============Welcome To our Reciept Generator==============");
	print("We will start with getting the store details");

	//Getting the store details from the user
	string storename,address,phone;
	insertValue("Type in the store name: ",storename);
	insertValue("Type in Store address: ", address);
	insertValue("Type in Phone Number: ", phone);

	if (storename.empty()) {
		print("========Error!: Incomplete details Please Kindly Fill in all required details to proceed=========\n");
		quick_exit(1);
	}

	//Saving it to our shop details
	shop.setDetails(storename, address, phone);

	//Our items vector this case we are using a 1D vector (dynamic array)
	vector<InvoiceItem> items = {};

	//Our primer to kick off the main event loop
	string action = "add";
	insertValue("\n\nWhat action do you want to take? add, print or exit: ", action);

	while (action=="add")
	{
		//initialize our buffer variables
		string name, descrption;
		float price;
		int qty;

		//Colection of data from the stdin
		print("\n=====Adding A new Store Item=====");
		insertValue("What is the name of the current product: ", name);
		insertValue("How much does it cost? ", price);
		insertValue("Extra notes(optional): ", descrption, true);
		insertValue("How many is the customer buying? ", qty);

		if (name.empty() || price == NULL || qty == NULL) {
			print("======Error: Incomplete details Please Kindly Fill in all required details to proceed======\n");
			continue;
		}

		//Creating the object and assigning properties
		InvoiceItem newItem = InvoiceItem();
		newItem.name = name;
		newItem.price = price;
		newItem.description = descrption;
		newItem.setQty(qty);

		// inserting into our list
		items.push_back(newItem);

		//Asking for the next course of action and possibly restart the loop
		insertValue("\nWhat action do you want to take? add, print or exit: ", action, true);
	}

	if (action == "print") {
		// handle the printing
	}


}