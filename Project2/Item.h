#ifndef _ITEM_H_
#define _ITEM_H_

class Item{
public:
	Item(char* in_name);//assume not stackable and weight is 1
	Item(char* in_name, float in_weight);//assume not stackable
	Item(char* in_name, float in_weight, bool in_isStackable);//assume stack of 1 if isStackable = true
	Item(char* in_name, float in_weight, bool in_isStackable, int in_stackCount);//if isStackable = false, stackCount will be ignored
	Item(char* in_name, float in_weight, int in_stackCount); //assume stackable
	Item(char* in_name, int in_stackCount);//assume stackable and weight is 1
	~Item();

	char* getName();//return name
	float getSingleWeight();//returns weight of 1 item in a stack or the weight of an item without a stack
	float getTotalWeight();//returns total weight of all items in a stack or the weight of an item without a stack
	bool getIsStackable();//returns weather or not the Item is stackable
	int getStackCount();//returns stackCount or 1 if the item is not stackable

	int changeStack(int in_amount); //returns the new total
	float ifChangeStack(int in_amount);//returns the change in weight that would hapen if changeStack were preformed with the same argument
	void mergeStack(Item in_other); //combinne two stacks
	float ifMergeStack(Item in_other);//returns the change in weight that would hapen if mergeStack were preformed with the same argument

private:

	char* name;
	float weight;//per item on stackables
	bool isStackable;
	int stackCount;
	//type
	//effects
};

#endif