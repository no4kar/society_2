#pragma once

#ifndef Society_H_
#define Society_H_
#define INDEX(x) ((x) - 1)

#include<iostream>
//#include<Windows.h> // for working SetConsoleCP(1251); SetConsoleOutputCP(1251);
#include<vector>
#include<string>
//#include<ctime>
//#include<fstream>

enum options {
	ADD_SOC,
	ADD_FAM,
	ADD_REL,
	SET_REL,
	GET_INFO_ALL_FAM,
	SAVE_DATA,
	LOAD_DATA,
	ER_FAM,
	ER_REL
};

class Human {
public:
	Human() :name("no_data"), sex("no_data"), age(0) {}

	~Human() {}

	Human(const Human & other) {
		this->name = other.name;
		this->sex = other.sex;
		this->age = other.age;
	}

	virtual void set_info() {
		std::cout << "\tName\t";
		std::cin >> name;
		std::cout << "\tSex\t";
		std::cin >> sex;
		std::cout << "\tAge\t";
		std::cin >> age;
	}

protected:
	std::string name;
	std::string sex;
	int age;

};

class Relative :public Human {
public:
	class Translation
	{
	public:
		Translation();
		~Translation();
		Translation& operator=(const Relative& other);
		//protected:
		char name[30];
		char sex[10];
		char how[20];
		char surname[30];
		int age;
	};

	Relative();
	~Relative();
	Relative(const Relative & other);
	Relative& operator=(const Translation & other);
	Relative& operator=(const Relative & other);

	void set_info() override;
	friend std::ostream& operator<<(std::ostream&, const Relative&);

private:
	std::string how;
	std::string surname;
};

void save_data(const std::vector<std::vector<Relative>> &);
void load_data(std::vector<std::vector<Relative>> &);
void insert_or_erase_fam(std::vector<std::vector<Relative>> &, const int &index, const int &quantity, const options &do_what);
void insert_or_erase_rel(std::vector<std::vector<Relative>> &, const int &fam_index, const int &rel_index, const int &quantity, const options&do_what);
void get_soc_info(std::vector<std::vector<Relative>> &);
bool check_lim(std::vector<std::vector<Relative>> &soc, const int& fam_index = 0, const int& rel_index = 0);
void msg();

#endif // !Society_H_