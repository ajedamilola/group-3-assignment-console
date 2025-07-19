#include<string>
#include<iostream>

using namespace std;

class Item {
public:
	string name;
	string description;
	float price = 0;
	void setQty(int newQty) {
		this->qty = newQty;
	}

	int incrementQty(int delta = 1) {
		if (delta < 1) {
			cout << "The change in qty must be greater than 0 so no change was made";
		}
		this->qty += delta;
		return this->qty;
	}

	int decrementQty(int delta = 1) {
		if (delta < 1) {
			cout << "The change in qty must be greater than 0 so no change was made";
		}
		this->qty -= delta;
		return this->qty;
	}

	int getQty() const {
		return this->qty;
	}
private:
	int qty = 0;
};

//This two items classes are children of the Item class they are in Item
class StoreItem : public Item {
public:
    std::string key;
    StoreItem(std::string key, std::string name, std::string description, float price) {
        this->key = key;
        this->name = name;
        this->description = description;
        this->price = price;
    }
    // Constructor for three arguments
    StoreItem(std::string name, std::string description, float price) {
        this->name = name;
        this->description = description;
        this->price = price;
        this->key = ""; // Default empty key
    }

    void setKey(std::string key) {
        this->key = key;
    }
};

class InvoiceItem : public Item {
public:
	bool affectInventory;
	float discountPercentage;
	InvoiceItem() {}
	static InvoiceItem createFromStoreItem(string key) {} 
};
