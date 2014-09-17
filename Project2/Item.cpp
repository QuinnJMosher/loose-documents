#include "Item.h"

Item::Item(char* in_name) {
	name = in_name;
	weight = 1.f;

	isStackable = false;
	stackCount = 1;
}

Item::Item(char* in_name, float in_weight) {
	name = in_name;

	if (weight > 0) {
		weight = in_weight;
	}
	else {
		weight = 1.f;
	}

	isStackable = false;
	stackCount = 1;
}

Item::Item(char* in_name, float in_weight, bool in_isStackable) {
	name = in_name;

	if (weight > 0) {
		weight = in_weight;
	}
	else {
		weight = 1.f;
	}

	isStackable = in_isStackable;
	stackCount = 1;
}

Item::Item(char* in_name, float in_weight, bool in_isStackable, int in_stackCount) {
	name = in_name;

	if (weight > 0) {
		weight = in_weight;
	} else {
		weight = 1.f;
	}

	isStackable = in_isStackable;
	if (isStackable && in_stackCount > 0) {
			stackCount = in_stackCount;
	} else {
		stackCount = 1;
	}
}

Item::Item(char* in_name, float in_weight, int in_stackCount) {
	name = in_name;

	if (weight > 0) {
		weight = in_weight;
	}
	else {
		weight = 1.f;
	}

	isStackable = true;
	if (in_stackCount > 0) {
		stackCount = in_stackCount;
	} else {
		stackCount = 1;
	}
}

Item::Item(char* in_name, int in_stackCount) {
	name = in_name;

	weight = 1.f;

	isStackable = true;
	if (in_stackCount > 0) {
		stackCount = in_stackCount;
	}
	else {
		stackCount = 1;
	}
}

Item::~Item() {

}

char* Item::getName() {
	return name;
}

float Item::getSingleWeight() {
	return weight;
}

float Item::getTotalWeight() {
	return (weight * stackCount);
}

bool Item::getIsStackable() {
	return isStackable;
}

int Item::getStackCount() {
	return stackCount;
}

int Item::changeStack(int in_ammount) {
	if (in_ammount + stackCount > 0) {
		stackCount += in_ammount;
	} else {
		stackCount = 0;
	}

	return stackCount;
}