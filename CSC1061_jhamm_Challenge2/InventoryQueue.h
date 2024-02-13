#pragma once

#include "InventoryADT.h"
#include <queue>
#include "Item.h"

class InventoryQueue : public InventoryADT
{
public:
	void addInv();
	void removeInv();
	void viewInv();

private:
	std::queue<Item *> invQueue;
};