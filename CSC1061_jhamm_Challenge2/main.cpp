// CSC_jhamm_Challenge2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
#include "Item.h"
#include "main.h"
#include "InventoryADT.h"
#include "InventoryStack.h"
#include "InventoryQueue.h"

using namespace std;

int main()
{
	InventoryADT *inventory;

	cout << "Would you like to use a Stack or Queue? (S|Q)" << endl;
	char option;

	while (true)
	{
		cin >> option;
		option = toupper(option);

		if (option == 'S')
		{
			inventory = new InventoryStack();
			break;
		}
		else if (option == 'Q')
		{
			inventory = new InventoryQueue();
			break;
		}
		else
		{
			cout << "Invalid option. Try again." << endl;
		}
	}

	cout << "************ Inventory Manager ************\n";

	cout << "A to add \nR to remove\nV to view\nX to exit\n";

	while (true)
	{
		cout << "Enter your Choice: ";
		// option search loop
		cin >> option;

		option = toupper(option);

		if (option == 'A')
		{
			inventory->addInv();
		}
		else if (option == 'R')
		{
			inventory->removeInv();
		}
		else if (option == 'V')
		{
			inventory->viewInv();
		}
		else if (option == 'X')
		{
			return 0;
		}
		else
		{
			cout << "Invalid Input! Try Again (A|R|V)\n";
		}
	}
}
