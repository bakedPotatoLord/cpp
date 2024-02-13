
#include <iostream>
#include <queue>
#include <vector>
#include "InventoryQueue.h"

void InventoryQueue::addInv()
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
	invQueue.push(item);
	cout << "new Item Succesfully added!" << endl;
}

void InventoryQueue::removeInv()
{
	Item *val = invQueue.front();
	invQueue.pop();

	cout << "Item Succesfully removed!" << endl;
	cout << "Serial Num : " << val->getSerialNum()
			 << " manufacture date: " << val->getManufactureDate()
			 << " lot num: " << val->getLotNum()
			 << '\n';
}

void InventoryQueue::viewInv()
{
	cout << endl;
	size_t len = invQueue.size();

	if (len == 0)
		cout << "nothing here yet..." << endl;

	vector<Item *> inventoryVect;
	inventoryVect.resize(len);

	for (int i = 0; i < len; i++)
	{
		Item *val = invQueue.front();
		invQueue.pop();

		cout << "Serial Num : " << val->getSerialNum()
				 << "\t\t manufacture date: " << val->getManufactureDate()
				 << "\t\t lot num: " << val->getLotNum()
				 << '\n';
		inventoryVect[i] = val;
	}

	for (auto item : inventoryVect)
	{
		invQueue.push(item);
	}
	cout << endl;
}
