//#include<iostream>
//#include<vector>
//#include<string>
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

void Human::operator<<(std::ostream& os) const {
	os << sex + ", " + name + " has " + std::to_string(age) + " years;\n";
}

void Human::operator>>(std::istream& is) {
	std::cout << "\tName\t";
	is >> name;
	std::cout << "\tGender\t";
	is >> sex;
	std::cout << "\tAge\t";
	is >> age;
	if (!is) {
		bad_insert(is); }
}