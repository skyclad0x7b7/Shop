#pragma once
#include "Item.h"

class Armor : public Item {
private:
	int m_defense;
public:
	Armor(string name, string description, int weight, int value, int defense);
	virtual void Describe();
};