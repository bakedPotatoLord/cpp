#pragma once

#include <string>

using namespace std;

class Item
{
private:
	unsigned int serialNum;
	string manufactureDate;
	unsigned int lotnum;

public:
	Item();
	Item(int, string, int);

	int getSerialNum();
	void setSerialNum(unsigned int);
	string getManufactureDate() const;
	void setmanufactureDate(string);
	int getLotNum() const;
	void setLotNum(unsigned int);
};