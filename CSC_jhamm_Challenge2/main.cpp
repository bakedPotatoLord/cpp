// CSC_jhamm_Challenge2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

#include "Inventory.h"
#include "main.h"

using namespace std;

int main()
{

	stack<Inventory> invStack;

	cout << "************ Inventory Manager using a Stack ************\n";

	cout << "A to add to stack\nR to remove from stack\nV to view inventory\n";
	char option;

	while (true) {
		//option search loop
		cin >> option;

		option = toupper(option);

		if (option == 'A') {
			addInv();
		}else if (option == 'R') {
			removeInv();
		}
		else if (option == 'V') {
			viewInv();
		}
		else {
			cout << "Invalid Input! Try Again (A|R|V)\n";
		}

	}

}

void addInv()
{

}

void removeInv()
{
}

void viewInv()
{
}

