#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item {
private:
	string m_name;
	string m_description;
	int m_weight;
	int m_value;

public:
	Item(string name, string description, int weight, int value);
	Item() {}
	virtual void Describe();
};