
#include<iostream>
#include<vector>
#include<string>
//#include<ctime>
//#include<fstream>
#include"Society_2.h"

Human::Human() :name("no_data"), sex("no_data"), age(0) {
}

Human::~Human() {
}

Human::Human(const Human & other) {
	this->name = other.name;
	this->sex = other.sex;
	this->age = other.age;
}

void Human::set_info() {
	std::cout << "\tName\t";
	std::cin >> name;
	std::cout << "\tSex\t";
	std::cin >> sex;
	std::cout << "\tAge\t";
	std::cin >> age;
}

void Human::operator<<(std::ostream& os) const {
	os << sex + ", " + name + " has " + std::to_string(age) + " years;\n";
}

Relative::Relative() :how("no_data"), surname("no_data") {
}

Relative::~Relative() {
}

Relative::Relative(const Relative & other) : Human(other) {//ctor of coping
	this->how = other.how;
	this->surname = other.surname;
}

Relative& Relative::operator=(const Relative::Translation & other) {
	this->name = other.name;
	this->sex = other.sex;
	this->age = other.age;
	this->how = other.how;
	this->surname = other.surname;
	return *this;
}

Relative& Relative::operator=(const Relative & other) {
	this->name = other.name;
	this->sex = other.sex;
	this->age = other.age;
	this->how = other.how;
	this->surname = other.surname;
	return *this;
}

void Relative::set_info() {
	::Human::set_info();
	std::cout << "\tHow in family\t";
	std::cin >> how;
	std::cout << "\tSurname\t";
	std::cin >> surname;
}

void Relative::operator<<(std::ostream& os) const {
	os << how + ", " + name + " " + surname + " has " + std::to_string(age) + " years;\n";
}

std::ostream& operator<<(std::ostream& os, const Human& obj) {
	obj << os;
	//os << a.how + ", " + a.name + " " + a.surname + " has " + std::to_string(a.age) + " years;\n";
	return os;
}