// Including necessary libraries and header files
#include <iostream>
#include <stack>
#include <vector>
#include "Item.h"						// Header file for item class
#include "main.h"						// Header file for main class
#include "InventoryADT.h"		// Header file for Inventory Abstract Data Type
#include "InventoryStack.h" // Header file for Inventory Stack implementation
#include "InventoryQueue.h" // Header file for Inventory Queue implementation

using namespace std;

// Main function where program execution begins
int main()
{
	// Pointer to an object of type InventoryADT
	InventoryADT *inventory;

	// Asking user to choose between using a Stack or Queue for managing inventory
	cout << "Would you like to use a Stack or Queue? (S|Q)" << endl;
	char option;

	// Loop until valid option is chosen
	while (true)
	{
		cin >> option;
		option = toupper(option);

		// Creating appropriate inventory object based on user choice
		if (option == 'S')
		{
			inventory = new InventoryStack(); // Creating InventoryStack object
			break;
		}
		else if (option == 'Q')
		{
			inventory = new InventoryQueue(); // Creating InventoryQueue object
			break;
		}
		else
		{
			cout << "Invalid option. Try again." << endl;
		}
	}

	// Displaying inventory management options
	cout << "************ Inventory Manager ************\n";
	cout << "A to add\nR to remove\nV to view\nX to exit\n";

	// Loop for managing inventory operations
	while (true)
	{
		cout << "Enter your Choice: ";

		// User input for desired operation
		cin >> option;
		option = toupper(option);

		// Performing respective operation based on user choice
		if (option == 'A')
		{
			inventory->addInv(); // Adding item to inventory
		}
		else if (option == 'R')
		{
			inventory->removeInv(); // Removing item from inventory
		}
		else if (option == 'V')
		{
			inventory->viewInv(); // Viewing inventory
		}
		else if (option == 'X')
		{
			return 0; // Exiting program
		}
		else
		{
			cout << "Invalid Input! Try Again (A|R|V|X)\n"; // Prompting for valid input
		}
	}
}
