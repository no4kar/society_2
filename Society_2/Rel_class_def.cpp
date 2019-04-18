
#include<iostream>
#include<vector>
#include<string>
//#include<ctime>
//#include<fstream>
#include"Society_2.h"

Relative::Relative() {
	how = "0";
	surname = "0";
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

std::ostream& operator<<(std::ostream& os, const Relative& a) {
	os << a.how + ", " + a.name + " " + a.surname + " has " + std::to_string(a.age) + " years;\n";
	return os;
}