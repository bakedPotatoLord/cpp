#pragma once

class InventoryADT
{
public:
	virtual void addInv() = 0;
	virtual void removeInv() = 0;
	virtual void viewInv() = 0;
};