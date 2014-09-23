#include <vector>
#include "Item.h"

#ifndef _Inventory_H_
#define _Inventory_H_

class Inventory {
public:

	Inventory(float in_weightLimit, int in_itemLimit);
	Inventory(float in_weightLimit);//no item limit
	Inventory(int in_itemLimit);//no weight limit
	Inventory();//no limits!
	~Inventory();

	int getItemLimit();
	bool setItemLimit(int in_itemLimit);//will not change if the argument is less than 1 or there is no limit. returns true if sucsessfull
	void removeItemLimit(); //sets itemLimit to -1 (an invalid argument for setItemLimit)
	bool addItemLimit(int in_itemLimit); //adds a limit if there is none (argument must valid), if there is a limit then call setItemLimit. returns true if sucsessful
	float getWeightLimit();
	bool setWeightLimit(float in_weightLimit);//will not change if the argument is less than 1 or there is no limit. returns true if sucsessfull
	void removeWeightLimit(); //sets weightLimit to -1 (an invalid argument for setWeightLimit)
	bool addWeightLimit(float in_weightLimit); //adds a limit if there is none (argument must valid), if there is a limit then call setWeightLimit. returns true if sucsessful
	int getItemsHeld();//reports items held
	float getWeightHeld();//reports weight held

	bool addItem(Item in_newItem);//adds new item to the vector if the limit alows, merges for other items of the same name if the item is stackable, if there is an item of the same name and item is not stackable then reject it, if item would exceed weight or item limit then reject it (returns true sucsessful)
	Item removeItem(char* in_itemName);//looks for an item with the given name, if it finds it, remove it from vector and return that object, otherwise return null
	Item getItem(char* in_itemName); //looks for item with given name, returns it if found or null if not found

private:

	std::vector<Item> Items;

	float weightLimit;//if value is -1 then there is no limit
	float weightHeld;

	int itemLimit;// if value is -1 then there is no limit
	int itemsHeld;

};

#endif