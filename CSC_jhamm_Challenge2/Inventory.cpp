#include "Inventory.h"

Inventory::Inventory(int serialNum = 0, string manDate = "0/0", int lotNum = 0)
{
	this->serialNum = serialNum;
	this->manufactureDate = manDate;
	this->lotnum = lotNum;
}

int Inventory::getSerialNum() const
{
	return serialNum;
}

void Inventory::setSerialNum(unsigned int serialNum)
{
	this->serialNum = serialNum;

}

string Inventory::getManufactureDate() const 
{
	return manufactureDate;
}

void Inventory::setmanufactureDate(string manDate)
{
	this->manufactureDate = manDate;
}

int Inventory::getLotNum() const
{
	return lotnum;
}

void Inventory::setLotNum(unsigned int lotnum)
{
	this->lotnum = lotnum;
}


