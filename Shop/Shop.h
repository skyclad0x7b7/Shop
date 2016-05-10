#pragma once
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include <fstream>
#include <memory>
#include <initializer_list>
#include <vector>

class Shop {
private:
	string m_name;
	string m_fileName;
	vector<shared_ptr<Item>> m_items;
	ifstream m_fileStream;
	
public:
	Shop() {}
	Shop(string name, initializer_list<shared_ptr<Item>>);
	Shop(string name, std::string fileName);
	void ShowItemList();
	void ReadDataFromFile();
};