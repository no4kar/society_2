#include<iostream>
#include<vector>
//#include<string>
//#include<ctime>
//#include<fstream>
#include"Society_2.h"

Relative::Translation::Translation() {
	strcpy_s(name, "empty");
	strcpy_s(sex, "empty");
	strcpy_s(how, "empty");
	strcpy_s(surname, "empty");
	age = 0;
}

Relative::Translation::~Translation() {
}

Relative::Translation& ::Relative::Translation::operator=(const Relative& other) {
	strcpy_s(this->name, other.name.c_str());
	strcpy_s(this->sex, other.sex.c_str());
	strcpy_s(this->how, other.how.c_str());
	strcpy_s(this->surname, other.surname.c_str());
	this->age = other.age;
	return *this;
}