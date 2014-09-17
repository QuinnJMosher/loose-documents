#include <vector>
#include "Item.h"

#ifndef _Inventory_H_
#define _Inventory_H_

class Inventory {
public:

private:
	std::vector<Item> Items;
	float weightCapacity;
	int itemLimit;
};

#endif