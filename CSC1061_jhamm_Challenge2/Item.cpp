#include "Item.h"

// Default constructor for Item class
Item::Item()
{
	// Initializing member variables to default values
	serialNum = 0;
	manufactureDate = "0/0";
	lotnum = 0;
}

// Parameterized constructor for Item class
Item::Item(int serialNum, string manDate, int lotNum)
{
	// Assigning values to member variables based on parameters
	this->serialNum = serialNum;
	this->manufactureDate = manDate;
	this->lotnum = lotNum;
}

// Getter function for retrieving serial number of the item
int Item::getSerialNum()
{
	return serialNum;
}

// Setter function for updating serial number of the item
void Item::setSerialNum(unsigned int serialNum)
{
	this->serialNum = serialNum;
}

// Getter function for retrieving manufacture date of the item
string Item::getManufactureDate() const
{
	return manufactureDate;
}

// Setter function for updating manufacture date of the item
void Item::setmanufactureDate(string manDate)
{
	this->manufactureDate = manDate;
}

// Getter function for retrieving lot number of the item
int Item::getLotNum() const
{
	return lotnum;
}

// Setter function for updating lot number of the item
void Item::setLotNum(unsigned int lotnum)
{
	this->lotnum = lotnum;
}
