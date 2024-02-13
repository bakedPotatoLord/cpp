
#include <iostream>
#include <stack>
#include <vector>
#include "InventoryStack.h"

using namespace std;

void InventoryStack::addInv()
{
	unsigned int serNum = 0;
	string manDate = "";
	unsigned int lotNum = 0;

	cout << "Enter serial number: ";
	cin >> serNum;
	cout << "Enter Manufacture Date: ";
	cin >> manDate;
	cout << "Enter lot Number: ";
	cin >> lotNum;

	Item *item = new Item(serNum, manDate, lotNum);
	invStack.push(item);
	cout << "new Item Succesfully added!" << endl;
}

void InventoryStack::removeInv()
{
	Item *val = invStack.top();
	invStack.pop();

	cout << "Item Succesfully removed!" << endl;
	cout << "Serial Num : " << val->getSerialNum()
			 << " manufacture date: " << val->getManufactureDate()
			 << " lot num: " << val->getLotNum()
			 << '\n';
}

void InventoryStack::viewInv()
{
	cout << endl;
	size_t len = invStack.size();

	if (len == 0)
		cout << "nothing here yet..." << endl;

	vector<Item *> inventoryVect;
	inventoryVect.resize(len);

	for (int i = 0; i < len; i++)
	{
		Item *val = invStack.top();
		invStack.pop();

		cout << "Serial Num : " << val->getSerialNum()
				 << "  manufacture date: " << val->getManufactureDate()
				 << "  lot num: " << val->getLotNum()
				 << '\n';
		inventoryVect[i] = val;
	}

	for (int i = len - 1; i >= 0; i--)
	{
		invStack.push(inventoryVect[i]);
	}
	cout << endl;
}
