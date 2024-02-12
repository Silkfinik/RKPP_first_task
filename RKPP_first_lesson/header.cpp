#include "header.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

Date Date::str_to_date(std::string str) {
	Date date;
	date.day = str.substr(0, str.find('.'));
	str.erase(0, str.find('.') + 1);
	date.month = str.substr(0, str.find('.'));
	str.erase(0, str.find('.') + 1);
	date.year = str;
	return date;
}

void str_cut(std::string& str, char symb) {
	str.erase(0, str.find(symb) + 1);
}

void Pets::read_file() {
	std::ifstream file("input.txt");
	try {
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::string o_name;
				std::string o_adress;
				std::string o_phone;
				Date o_date;
				std::string a_type;
				std::string a_name;
				unsigned __int16 a_age;
				o_name = line.substr(0, line.find(';'));
				str_cut(line, ';');
				o_adress = line.substr(0, line.find(';'));
				str_cut(line, ';');
				o_phone = line.substr(0, line.find(';'));
				str_cut(line, ';');
				o_date = Date::str_to_date(line.substr(0, line.find(';')));
				str_cut(line, ';');
				a_type = line.substr(0, line.find(';'));
				str_cut(line, ';');
				a_name = line.substr(0, line.find(';'));
				str_cut(line, ';');
				a_age = std::stoi(line);
				if (a_type == "Собака") {
					Dog pet(a_name, a_age, o_name, o_adress, o_phone, o_date);
					dogs[o_name].push_back(pet);
				}
				else if (a_type == "Кошка") {
					Cat pet(a_name, a_age, o_name, o_adress, o_phone, o_date);
					cats[o_name].push_back(pet);
				}
				else if (a_type == "Попугай") {
					Parrot pet(a_name, a_age, o_name, o_adress, o_phone, o_date);
					parrots[o_name].push_back(pet);
				}
				else if (a_type == "Рыбка") {
					Fish pet(a_name, a_age, o_name, o_adress, o_phone, o_date);
					fish[o_name].push_back(pet);
				}
				else if (a_type == "Свинка") {
					Pig pet(a_name, a_age, o_name, o_adress, o_phone, o_date);
					pigs[o_name].push_back(pet);
				}
				else {
					throw "Unknown animal type";
				}
			}
		}
		else {
			throw "File not found";
		}
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
}

void Pets::owner_dif_types() {
	std::map <std::string, unsigned __int16> owners;
	for (auto& i : dogs) {
		owners[i.first]++;
	}
	for (auto& i : cats) {
		owners[i.first]++;
	}
	for (auto& i : parrots) {
		owners[i.first]++;
	}
	for (auto& i : fish) {
		owners[i.first]++;
	}
	for (auto& i : pigs) {
		owners[i.first]++;
	}
	for (auto& i : owners) {
		std::cout << i.first << " - " << i.second << std::endl;
	}
}

void Pets::one_type(const unsigned __int16& input) {
	std::set <std::string> uniq_owners;
	std::set <std::string> uniq_pets;
	std::string type;
	bool flag = true;
	switch (input)
	{
	case 1:
		for (auto& i : dogs) {
			uniq_owners.insert(i.first);
			for (auto& j : i.second) {
				uniq_pets.insert(j.get_animal_name());
			}
		}
		type = "Собака";
		break;
	case 2:
		for (auto& i : cats) {
			uniq_owners.insert(i.first);
			for (auto& j : i.second) {
				uniq_pets.insert(j.get_animal_name());
			}
		}
		type = "Кошка";
		break;
	case 3:
		for (auto& i : parrots) {
			uniq_owners.insert(i.first);
			for (auto& j : i.second) {
				uniq_pets.insert(j.get_animal_name());
			}
		}
		type = "Попугай";
		break;
	case 4:
		for (auto& i : fish) {
			uniq_owners.insert(i.first);
			for (auto& j : i.second) {
				uniq_pets.insert(j.get_animal_name());
			}
		}
		type = "Рыбка";
		break;
	case 5:
		for (auto& i : pigs) {
			uniq_owners.insert(i.first);
			for (auto& j : i.second) {
				uniq_pets.insert(j.get_animal_name());
			}
		}
		type = "Свинка";
		break;
	default:
		std::cout << "Unknown type" << std::endl;
		flag = false;
		break;
	}
	if(flag){
		std::cout << "Type: " << type << std::endl;
		std::cout << "Unique owners: ";
		for (auto& i : uniq_owners) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
		std::cout << "Unique pets: ";
		for (auto& i : uniq_pets) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}

void Pets::pets_by_name(const std::string& input) {
	unsigned __int16 count = 0;
	bool flag = false;
	for (auto& i : dogs) {
		for (auto& j : i.second) {
			if (j.get_animal_name() == input) {
				count++;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	flag = false;
	for (auto& i : cats) {
		for (auto& j : i.second) {
			if (j.get_animal_name() == input) {
				count++;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	flag = false;
	for (auto& i : parrots) {
		for (auto& j : i.second) {
			if (j.get_animal_name() == input) {
				count++;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	flag = false;
	for (auto& i : fish) {
		for (auto& j : i.second) {
			if (j.get_animal_name() == input) {
				count++;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	flag = false;
	for (auto& i : pigs) {
		for (auto& j : i.second) {
			if (j.get_animal_name() == input) {
				count++;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	std::cout << "Pets species named " << input << ": " << count << std::endl;
}

void Pets::print_o_y_by_type(std::map<unsigned __int16, std::string> age_name, std::string type) {
	std::cout << "Oldest " << type << ": " << age_name.rbegin()->second << " - " << age_name.rbegin()->first << std::endl;
	std::cout << "Youngest " << type << ": " << age_name.begin()->second << " - " << age_name.begin()->first << std::endl;
}

void Pets::oldest_youngest_pet() {
	{
		std::map <unsigned __int16, std::string> pets;
		for (auto& i : dogs) {
			for (auto& j : i.second) {
				pets[j.get_animal_age()] = j.get_animal_name();
			}
		}
		print_o_y_by_type(pets, "dog");
	}
{
		std::map <unsigned __int16, std::string> pets;
		for (auto& i : cats) {
			for (auto& j : i.second) {
				pets[j.get_animal_age()] = j.get_animal_name();
			}
		}
		print_o_y_by_type(pets, "cat");
	}
	{
		std::map <unsigned __int16, std::string> pets;
		for (auto& i : parrots) {
			for (auto& j : i.second) {
				pets[j.get_animal_age()] = j.get_animal_name();
			}
		}
		print_o_y_by_type(pets, "parrot");
	}
	{
		std::map <unsigned __int16, std::string> pets;
		for (auto& i : fish) {
			for (auto& j : i.second) {
				pets[j.get_animal_age()] = j.get_animal_name();
			}
		}
		print_o_y_by_type(pets, "fish");
	}
	{
		std::map <unsigned __int16, std::string> pets;
		for (auto& i : pigs) {
			for (auto& j : i.second) {
				pets[j.get_animal_age()] = j.get_animal_name();
			}
		}
		print_o_y_by_type(pets, "pig");
	}
}