#pragma once

#include "InventoryADT.h"
#include <stack>
#include "Item.h"

class InventoryStack : public InventoryADT
{
public:
	void addInv();
	void removeInv();
	void viewInv();

private:
	std::stack<Item *> invStack;
};