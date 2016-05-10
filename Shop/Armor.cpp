#include "Armor.h"

Armor::Armor(string name, string description, int weight, int value, int defense) : m_defense(defense), Item(name, description, weight, value) {}

void Armor::Describe() {
	Item::Describe();
	cout << "Defense     = " << m_defense << endl;
}