#include "Potion.h"

Potion::Potion(string name, string description, int weight, int value, string type, int recover_point) : Item(name, description, weight, value), m_type(type), m_recover_point(recover_point) {}

void Potion::Describe() {
	Item::Describe();
	cout << "Type        = " << m_type << endl;
	cout << "Capacity    = " << m_recover_point << endl;
}