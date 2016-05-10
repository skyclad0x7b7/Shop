#pragma once
#include "Item.h"

class Weapon : public Item {
private:
	int m_damage;
public:
	Weapon(string name, string description, int weight, int value, int damage);
	virtual void Describe();
};