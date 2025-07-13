// group-6-assignment-console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Shop.h"
#include "Item.h"

int main()
{
    Shop shop;
    shop.setDetails("Dammy Shop", "22, LASU Street", "09161689303");

    StoreItem newStoreItem = StoreItem("Five Alive","This is a five alive ohh",200);
    newStoreItem.setQty(20);
    cout << newStoreItem.getQty();
    
    //This is Just a test
    cout << "Shop Name:"  << shop.name << "\nAddress:" << shop.address << "\nPhone:" << shop.phone;
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
