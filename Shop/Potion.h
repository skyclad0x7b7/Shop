#pragma once
#include "Item.h"

class Potion : public Item {
protected:
	string m_type;
	int m_recover_point;
public:
	Potion() {}
	Potion(string name, string description, int weight, int value, string type, int recover_point);
	virtual void Describe();
};