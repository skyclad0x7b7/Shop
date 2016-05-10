#include "Weapon.h"

Weapon::Weapon(string name, string description, int weight, int value, int damage) : m_damage(damage), Item::Item(name, description, weight, value) { }

void Weapon::Describe(){
	Item::Describe();
	cout << "Damage      = " << m_damage << endl;
}