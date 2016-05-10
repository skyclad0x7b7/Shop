#include "Item.h"

Item::Item(string name, string description, int weight, int value) : m_name(name), m_description(description), m_weight(weight), m_value(value) {}

void Item::Describe(){
	cout << "Name        = " << this->m_name << endl;
	cout << "Description = " << this->m_description << endl;
	cout << "Weight      = " << this->m_weight << endl;
	cout << "Value       = " << this->m_value << endl;
}