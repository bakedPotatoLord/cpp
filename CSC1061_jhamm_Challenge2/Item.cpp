

#include "Item.h"

Item::Item()
{
	serialNum = 0;
	manufactureDate = "0/0";
	lotnum = 0;
}

Item::Item(int serialNum = 0, string manDate = "0/0", int lotNum = 0)
{
	this->serialNum = serialNum;
	this->manufactureDate = manDate;
	this->lotnum = lotNum;
}

int Item::getSerialNum()
{
	return serialNum;
}

void Item::setSerialNum(unsigned int serialNum)
{
	this->serialNum = serialNum;
}

string Item::getManufactureDate() const
{
	return manufactureDate;
}

void Item::setmanufactureDate(string manDate)
{
	this->manufactureDate = manDate;
}

int Item::getLotNum() const
{
	return lotnum;
}

void Item::setLotNum(unsigned int lotnum)
{
	this->lotnum = lotnum;
}
