#include<vector>
#include<iostream>
#include "Item.h"


#pragma once

//This file include helper functions and broken down sections to make our entrypoint 
using namespace std;

//Insert value is a overloaded function thwse are helper functions 
void insertValue(string message, string& value, bool succeedsNumericValue = false) {
	cout << message;
	if (succeedsNumericValue) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	getline(cin, value);
}
void insertValue(string message, float& value, bool succeedsNumericValue = false) {
	if (succeedsNumericValue) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << message;
	cin >> value;
}
void insertValue(string message, int& value, bool succeedsNumericValue = false) {
	if (succeedsNumericValue) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << message;
	cin >> value;
}

void print(string message) {
	cout << message << "\n";
}
void printReceipt(const Shop& shop, const vector<InvoiceItem>& items) {
	//Clearing the console. but OS agnostic
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif

	system("cls");
	cout << "======================= RECEIPT =======================\n";
	cout << "=================" << shop.name << "================\n";
	cout << shop.address << "\n";
	cout << "Call us on: " << shop.phone << "\n";
	cout << "=============================================\n";

	float total = 0;
	for (int i = 0; i < items.size(); ++i) {
		const InvoiceItem& item = items[i];
		float itemTotal = item.price * item.getQty();

		cout << i + 1 << ". " << item.name;
		if (!item.description.empty()) {
			cout << " (" << item.description << ")";
		}
		cout << "\n";
		cout << "   Price: #" << item.price << " x " << item.getQty() << " = #" << itemTotal << "\n";

		total += itemTotal;
	}

	cout << "=============================================\n";
	cout << "TOTAL: #" << total << "\n";
	cout << "=============================================\n";
	cout << "     Thank you for shopping with us!\n";
	cout << "=============================================\n";
}

void collectShopDetails(Shop& shop) {
	print("We will start with getting the store details");

	//Getting the store details from the user
	string storename, address, phone;

	insertValue("Type in the store name: ", storename);
	insertValue("Type in Store address: ", address);
	insertValue("Type in Phone Number: ", phone);

	if (storename.empty()) {
		print("========Error!: Incomplete details Please Kindly Fill in all required details to proceed=========\n");
		quick_exit(1);
	}

	//Saving it to our shop details
	shop.setDetails(storename, address, phone);
}