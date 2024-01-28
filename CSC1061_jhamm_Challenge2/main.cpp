// CSC_jhamm_Challenge2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

#include "Inventory.h"
#include "main.h"

using namespace std;

stack<Inventory> invStack;

int main()
{


	cout << "************ Inventory Manager using a Stack ************\n";

	cout << "A to add to stack\nR to remove from stack\nV to view inventory\n";
	char option;

	while (true) {
		cout << "Enter your Choice: ";
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
	unsigned int serNum = 0;
	string manDate = "";
	unsigned int lotNum = 0;

	cout << "Enter serial number: ";
	cin  >> serNum;
	cout << "Enter Manufacture Date: ";
	cin >> manDate;
	cout << "Enter lot Number: ";
	cin >> lotNum;


	invStack.push(*(new Inventory (serNum, manDate, lotNum)));
	cout << "new Inventory Succesfully added!";
}

void removeInv()
{
}

void viewInv()
{
	size_t len = invStack.size();



	for (int i = 0; i < len;i++) {
		Inventory* val = &invStack.top();


		cout << "Serial Num :" << val->getSerialNum() << '\n';
		
	}
}

