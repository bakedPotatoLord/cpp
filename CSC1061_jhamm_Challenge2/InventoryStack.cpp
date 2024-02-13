#include <iostream>
#include <stack>
#include <vector>
#include "InventoryStack.h"

using namespace std;

// Function to add an item to the inventory stack
void InventoryStack::addInv()
{
	// Variables to store item details
	unsigned int serNum = 0;
	string manDate = "";
	unsigned int lotNum = 0;

	// Prompting user for item details
	cout << "Enter serial number: ";
	cin >> serNum;
	cout << "Enter Manufacture Date: ";
	cin >> manDate;
	cout << "Enter lot Number: ";
	cin >> lotNum;

	// Creating a new item with the provided details
	Item *item = new Item(serNum, manDate, lotNum);
	invStack.push(item); // Adding the item to the inventory stack
	cout << "New Item Successfully added!" << endl;
}

// Function to remove an item from the inventory stack
void InventoryStack::removeInv()
{
	Item *val = invStack.top(); // Getting the top item from the inventory stack
	invStack.pop();							// Removing the top item from the inventory stack

	cout << "Item Successfully removed!" << endl;
	// Displaying details of the removed item
	cout << "Serial Num : " << val->getSerialNum()
			 << " Manufacture date: " << val->getManufactureDate()
			 << " Lot num: " << val->getLotNum()
			 << '\n';
}

// Function to view items in the inventory stack
void InventoryStack::viewInv()
{
	cout << endl;
	size_t len = invStack.size(); // Getting the size of the inventory stack

	if (len == 0)
		cout << "Nothing here yet..." << endl;

	vector<Item *> inventoryVect;
	inventoryVect.resize(len); // Resizing vector to store items temporarily

	// Loop to retrieve and display items from the inventory stack
	for (int i = 0; i < len; i++)
	{
		Item *val = invStack.top(); // Getting the top item from the inventory stack
		invStack.pop();							// Removing the top item from the inventory stack

		// Displaying details of the item
		cout << "Serial Num : " << val->getSerialNum()
				 << "  Manufacture date: " << val->getManufactureDate()
				 << "  Lot num: " << val->getLotNum()
				 << '\n';
		inventoryVect[i] = val; // Storing the item in the temporary vector
	}

	// Restoring items back to the inventory stack from the temporary vector
	for (int i = len - 1; i >= 0; i--)
	{
		invStack.push(inventoryVect[i]); // Pushing items back to the inventory stack
	}
	cout << endl;
}
