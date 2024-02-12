#include <iostream> 
#include <windows.h>
#include "header.h"

void menu(Pets& pets);

int main() {
	Pets pet;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	pet.read_file();
	menu(pet);
	return 0;
}

void menu(Pets& pets) {
	std::cout << "1. Number of different animal species per owner\n";
	std::cout << "2. All owners and nicknames of a particular type of animal\n";
	std::cout << "3. The number of species that bear a certain name\n";
	std::cout << "4. The age of the oldest and youngest animal of each species.\n";
	std::cout << "0. Exit\n";
	while (true) {
		unsigned __int16 choice;
		std::string name;
		std::cout << "Enter the number: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			pets.owner_dif_types();
			break;
		case 2:
			std::cout << "1. Dog\n";
			std::cout << "2. Cat\n";
			std::cout << "3. Parrot\n";
			std::cout << "4. Fish\n";
			std::cout << "5. Pig\n";
			std::cout << "Enter the type: ";
			std::cin >> choice;
			pets.one_type(choice);
			break;
		case 3:
			std::cout << "Enter the name: ";
			std::cin >> name;
			pets.pets_by_name(name);
			break;
		case 4:
			pets.oldest_youngest_pet();
			break;
		case 0:
			return;
		default:
			std::cout << "Invalid number\n";
			break;
		}
	}
}