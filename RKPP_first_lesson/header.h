#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Date {
	std::string day;
	std::string month;
	std::string year;
	Date() : day("00"), month("00"), year("0000") {};
	Date(std::string d, std::string m, std::string y) : day(std::move(d)), month(std::move(m)), year(std::move(y)) {};
	static Date str_to_date(std::string str);
};

class Owner {
	private:
		std::string owner_name;
		std::string owner_address;
		std::string phone_number;
		Date birth_date;
	public:
		std::string get_owner_name() {
			return owner_name;
		}
		Owner () : owner_name("Unknown"), owner_address("Unknown"), phone_number("Unknown"), birth_date() {};
		Owner (std::string name, std::string address, std::string phone, Date& birth) :
			owner_name(std::move(name)), owner_address(std::move(address)), phone_number(std::move(phone)), birth_date(birth) {};
};

class Animal : public Owner{
	private:
	unsigned __int16 animal_age;
	std::string animal_name;
	public:
		Animal (const std::string a_name, unsigned __int16 a_age,const std::string o_name,
			const std::string o_address, const std::string o_phone, Date o_birth) :
			 animal_name(a_name), animal_age(a_age), Owner(o_name, o_address, o_phone, o_birth) {};
		static void print(std::string str) {
			std::cout << str << std::endl;
		}
		std::string get_animal_name() {
			return animal_name;
		}
		unsigned __int16 get_animal_age() {
			return animal_age;
		}
};

class Dog : public Animal {
public:
	using Animal::Animal;
	static void bark() {
		print("Bark");
	}
	static void wagging() {
		print("Wagging its tail");
	}
};

class Cat : public Animal {
public:
	using Animal::Animal;
	static void meow() {
		print("Meow");
	}
	static void playing() {
		print("Playing with a ball");
	}
};

class Parrot : public Animal {
public:
	using Animal::Animal;
	static void talk() {
		print("Hello");
	}
	static void imitating() {
		print("Imitating human speech");
	}
};

class Fish : public Animal {
public:
	using Animal::Animal;
	static void swim() {
		print("Swimming");
	}
	static void blowing() {
		print("Blowing bubbles");
	}
};

class Pig : public Animal {
public:
	using Animal::Animal;
	static void oink() {
		print("Oink");
	}
	static void running_circles() {
		print("Running around in circles");
	}
};

struct Pets {
	std::map<std::string, std::vector<Dog> > dogs;
	std::map<std::string, std::vector<Cat> > cats;
	std::map<std::string, std::vector<Parrot> > parrots;
	std::map<std::string, std::vector<Fish> > fish;
	std::map<std::string, std::vector<Pig> > pigs;
	void read_file();
	void owner_dif_types();
	void one_type(const unsigned __int16& input);
	void pets_by_name(const std::string& input);
	void print_o_y_by_type(std::map<unsigned __int16, std::string> age_name, std::string type);
	void oldest_youngest_pet();
};
