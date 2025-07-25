// group-3-assignment-console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Database.h"
#include "Helpers.h"
#include<iostream>
#include<vector>
#include<string>


using namespace std;

bool Shop::recordExist = false;
sqlite3* Shop::db;
Shop Shop::dbShop;

int main()
{
	
	//Initialize Our SQL database for persistence
	bool databaseInitialized = initDatabase();

	if (!databaseInitialized) {
		cerr << "Unable to initialize application database exiting";
		quick_exit(1);
	}

	//creating our shop
	Shop shop = Shop(true);

	print("===============Welcome To our Reciept Generator==============");

	if (shop.name.empty()) {
		//means that the shop details is not in the DB
		collectShopDetails(shop);
	}
	else {
		print("Shop Details retrieved from database");
	}

	//Our items vector this case we are using a 1D vector (dynamic array)
	vector<InvoiceItem> items = {};

	//Our primer to kick off the main event loop
	string action = "add";
	while (true) {  // Infinite Loop
		insertValue("What action do you want to take? add, clear, print, set-data or exit: ", action);

		if (action == "add")
		{
			//initialize our buffer variables
			string name, descrption;
			float price;
			int qty;

			//Colection of data from the stdin
			print("\n=====Adding A new Store Item=====");
			insertValue("What is the name of the current product: ", name);
			insertValue("How much does it cost? ", price);
			insertValue("How many is the customer buying? ", qty, true);
			insertValue("Extra notes(optional): ", descrption, true);

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
		}
		else if (action == "print") {
			printReceipt(shop, items);
		}
		else if (action == "set-data") {
			collectShopDetails(shop);
		}
		else if (action == "clear") {
			items.clear();
			print("=====Items cleared successfully=====");
		}
		else if (action=="exit") {
			print("Thank you and Good Bye!");
			exit(1);
		}
		else {
			print("Unknown command: The available command includes: add, clear, print, set-data and exit");
		}
	}

}
