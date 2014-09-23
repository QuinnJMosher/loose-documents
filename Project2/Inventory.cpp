#include "Inventory.h"
#include "Item.h"
#include <iostream>
#include <vector>

Inventory::Inventory(float in_weightLimit, int in_itemLimit) {
	weightLimit = in_weightLimit;
	itemLimit = in_itemLimit;

	weightHeld = 0;
	itemsHeld = 0;
}

Inventory::Inventory(float in_weightLimit) {
	weightLimit = in_weightLimit;
	itemLimit = -1;

	weightHeld = 0;
	itemsHeld = 0;
}

Inventory::Inventory(int in_itemLimit) {
	weightLimit = -1;
	itemLimit = in_itemLimit;

	weightHeld = 0;
	itemsHeld = 0;
}

Inventory::Inventory() {
	weightLimit = -1;
	itemLimit = -1;

	weightHeld = 0;
	itemsHeld = 0;
}

Inventory::~Inventory() {
	Items.~vector();
}

int Inventory::getItemLimit() {
	return itemLimit;
}

bool Inventory::setItemLimit(int in_itemLimit) {
	if (in_itemLimit > 0 && in_itemLimit > itemsHeld && itemLimit != -1) {
		itemLimit = in_itemLimit;
		return true;
	} 
	return false;
}

void Inventory::removeItemLimit() {
	itemLimit = -1;
}

bool Inventory::addItemLimit(int in_itemLimit) {
	if (itemLimit != -1) {
		return setItemLimit(in_itemLimit);
	} else if (in_itemLimit > 0 && in_itemLimit > itemsHeld) {
		itemLimit = in_itemLimit;
		return true;
	}
	return false;
}

float Inventory::getWeightLimit() {
	return weightLimit;
}

bool Inventory::setWeightLimit(float in_weightLimit) {
	if (in_weightLimit > 0 && in_weightLimit > weightHeld && weightLimit != -1) {
		weightLimit = in_weightLimit;
		return true;
	}
	return false;
}

void Inventory::removeWeightLimit() {
	weightLimit = -1;
}

bool Inventory::addWeightLimit(float in_weightLimit) {
	if (weightLimit != -1) {
		return setWeightLimit(in_weightLimit);
	}
	else if (in_weightLimit > 0 && in_weightLimit > weightHeld) {
		weightLimit = in_weightLimit;
		return true;
	}
	return false;
}

int Inventory::getItemsHeld() {
	return itemsHeld;
}

float Inventory::getWeightHeld() {
	return weightHeld;
}

bool Inventory::addItem(Item in_newItem) {
	if ((weightLimit == -1 || in_newItem.getTotalWeight() + weightHeld < weightLimit) && (itemLimit == -1 || itemsHeld < itemLimit)) {//make sure item will fit in inventory

		for (int i = 0; i < Items.size(); i++) {//check for similarly named items
			if (strcmp(in_newItem.getName(), Items[i].getName()) == 0) {//compare names
				if (in_newItem.getIsStackable() && Items[i].getIsStackable()) {//make sure both are stackable
					weightHeld += in_newItem.getTotalWeight();
					return Items[i].mergeStack(in_newItem);//add items
				}
				return false;// if the name matches but either of the items with that name can't stack then we have to reject it because there isn't another way to identify items (yet?)
			}
		}
		//if there are no items with the same name then we can add it
		itemsHeld++;
		weightHeld += in_newItem.getTotalWeight();
		Items.push_back(in_newItem);
		return true;

	}
	return false;//if the item wont fit then we cant accept it
}

Item Inventory::removeItem(char* in_item) {
	for (int i = 0; i < Items.size(); i++) {//check for similarly named items
		if (strcmp(in_item, Items[i].getName()) == 0) {//compare names

			Item temp = Items[i];
			weightHeld -= temp.getTotalWeight();
			itemsHeld--;
			Items.erase(Items.begin() + i);
			return temp;

		}
	}
	return NULL;
}

Item Inventory::getItem(char* in_item) {
	for (int i = 0; i < Items.size(); i++) {//check for similarly named items
		if (strcmp(in_item, Items[i].getName()) == 0) {//compare names

			return Items[i];

		}
	}
	return NULL;
}