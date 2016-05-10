#include "Shop.h"

Shop::Shop(string name, initializer_list<shared_ptr<Item>> itemList) : m_name(name) {
	for (auto& i : itemList) {
		m_items.push_back(i);
	}
}

Shop::Shop(string name, std::string fileName) : m_name(name), m_fileName(fileName) {
	m_fileStream.open(m_fileName);
	if (!m_fileStream.is_open()){
		throw bad_exception();
	}
	ReadDataFromFile();
}

void Shop::ShowItemList() {
	cout << "Welcome to Weapon / Armor Shop!" << endl << "- Item List -" << endl;
	for (auto& i : m_items) {
		i->Describe();
		cout << endl;
	}
}

void Shop::ReadDataFromFile() {
	string data = "";
	while (getline(m_fileStream, data)) {
		string tokenizedString = data;
		string type, name, description;
		int weight, value, personal_value;

		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
		type = tokenizedString.substr(0, tokenizedString.find("\""));
		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

		if (type != "Weapon" && type != "Armor" && type != "Potion") throw bad_exception();

		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
		name = tokenizedString.substr(0, tokenizedString.find("\""));
		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
		description = tokenizedString.substr(0, tokenizedString.find("\""));
		tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

		tokenizedString = tokenizedString.substr(tokenizedString.find(" ") + 1);
		weight = atoi(tokenizedString.substr(0, tokenizedString.find(" ")).c_str());
		tokenizedString = tokenizedString.substr(tokenizedString.find(" ") + 1);
		value = atoi(tokenizedString.substr(0, tokenizedString.find(" ")).c_str());
		tokenizedString = tokenizedString.substr(tokenizedString.find(" ") + 1);

		if (type == "Weapon") {
			personal_value = atoi(tokenizedString.c_str());
			m_items.push_back(make_shared<Weapon>(name, description, weight, value, personal_value));
		}
		else if (type == "Armor") {
			personal_value = atoi(tokenizedString.c_str());
			m_items.push_back(make_shared<Armor>(name, description, weight, value, personal_value));
		}
		else {
			tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);
			string recover_type = tokenizedString.substr(0, tokenizedString.find("\""));
			tokenizedString = tokenizedString.substr(tokenizedString.find("\"") + 1);

			personal_value = atoi(tokenizedString.c_str());
			m_items.push_back(make_shared<Potion>(name, description, weight, value, recover_type, personal_value));
		}
	}
}