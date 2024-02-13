#include <iostream>
#include <queue>
#include <vector>
#include "InventoryQueue.h"

// Function to add an item to the inventory queue
void InventoryQueue::addInv()
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
	invQueue.push(item); // Adding the item to the inventory queue
	cout << "New Item Successfully added!" << endl;
}

// Function to remove an item from the inventory queue
void InventoryQueue::removeInv()
{
	Item *val = invQueue.front(); // Getting the front item from the inventory queue
	invQueue.pop();								// Removing the front item from the inventory queue

	cout << "Item Successfully removed!" << endl;
	// Displaying details of the removed item
	cout << "Serial Num : " << val->getSerialNum()
			 << " Manufacture date: " << val->getManufactureDate()
			 << " Lot num: " << val->getLotNum()
			 << '\n';
}

// Function to view items in the inventory queue
void InventoryQueue::viewInv()
{
	cout << endl;
	size_t len = invQueue.size(); // Getting the size of the inventory queue

	if (len == 0)
		cout << "Nothing here yet..." << endl;

	vector<Item *> inventoryVect;
	inventoryVect.resize(len); // Resizing vector to store items temporarily

	// Loop to retrieve and display items from the inventory queue
	for (int i = 0; i < len; i++)
	{
		Item *val = invQueue.front(); // Getting the front item from the inventory queue
		invQueue.pop();								// Removing the front item from the inventory queue

		// Displaying details of the item
		cout << "Serial Num : " << val->getSerialNum()
				 << "\t\t Manufacture date: " << val->getManufactureDate()
				 << "\t\t Lot num: " << val->getLotNum()
				 << '\n';
		inventoryVect[i] = val; // Storing the item in the temporary vector
	}

	// Restoring items back to the inventory queue from the temporary vector
	for (auto item : inventoryVect)
	{
		invQueue.push(item); // Pushing items back to the inventory queue
	}
	cout << endl;
}
