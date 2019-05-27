//#include<iostream>
//#include<vector>
//#include<string>
//#include<ctime>
//#include<fstream>
#include"Society_2.h"

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

void Relative::operator<<(std::ostream& os) const {
	os << how + ", " + name + " " + surname + " has " + std::to_string(age) + " years;\n";
}

void Relative::operator>>(std::istream& is) {
	((Human&)*this) >> is;
	std::cout << "\tHow in family\t";
	is >> how;
	std::cout << "\tSurname\t";
	is >> surname;
}
