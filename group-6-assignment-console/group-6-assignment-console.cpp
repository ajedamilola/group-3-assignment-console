// group-6-assignment-console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Shop.h"
#include "Item.h"
#include <vector>

using namespace std;

//Insert value is a overloaded function
void insertValue(string message, string& value) {
	cout << message;
	cin >> value;
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
	Shop shop = Shop();

	print("============Welcome To our Reciept Generator=========");
	print("We will start with getting the store details");
	string storename,address,phone;
	insertValue("Type in the store name: ",storename);
	insertValue("Type in Store address: ", address);
	insertValue("Type in Phone Number: ", phone);

	shop.setDetails(storename, address, phone);

	//Main Logic of adding items
	vector<InvoiceItem> items = {};

	string action = "add";
	insertValue("\n\nWhat action do you want to take? add, print or exit: ", action);

	while (action=="add")
	{
		string name, descrption;
		float price;
		int qty;

		print("\n=====Adding A new Store Item=====");
		insertValue("What is the name of the current product: ", name);
		insertValue("How much does it cost? ", price);
		insertValue("Extra notes: ", descrption);
		insertValue("How many is the customer buying? ", qty);
		InvoiceItem newItem = InvoiceItem();
		newItem.name = name;
		newItem.price = price;
		newItem.description = descrption;
		newItem.setQty(qty);

		items.push_back(newItem);
		insertValue("What action do you want to take? add, print or exit", action);
	}

	if (action == "print") {

	}


}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
