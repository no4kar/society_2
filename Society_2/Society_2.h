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
protected:
	std::string name;
	std::string sex;
	int age;

public:
	Human();
	Human(const Human&);
	virtual void operator<<(std::ostream&) const;
	virtual void operator>>(std::istream&);
	
	virtual~Human(); //{}
};

class Relative :public Human {
	std::string how;
	std::string surname;
public:
	class Translation
	{
	public:
		Translation();
		~Translation();
		Translation& operator=(const Relative&);
		//protected:
		char name[30];
		char sex[10];
		char how[20];
		char surname[30];
		int age;
	};

	Relative();
	Relative(const Relative&);
	Relative& operator=(const Translation&);
	Relative& operator=(const Relative&);
	void operator<<(std::ostream&) const override;
	void operator>>(std::istream&)override;
	~Relative();
};

std::ostream& operator<<(std::ostream&, const Human&);
std::istream& operator>>(std::istream&, Human&);
std::istream& bad_insert(std::istream&);
void save_data(const std::vector<std::vector<Relative>> &);
void load_data(std::vector<std::vector<Relative>> &);
void insert_or_erase_fam(std::vector<std::vector<Relative>> &, const int &index, const int &quantity, const options &do_what);
void insert_or_erase_rel(std::vector<std::vector<Relative>> &, const int &fam_index, const int &rel_index, const int &quantity, const options&do_what);
void get_soc_info(std::vector<std::vector<Relative>> &);
bool check_lim(std::vector<std::vector<Relative>> &soc, const int& fam_index = 0, const int& rel_index = 0);
void msg();

#endif // !Society_H_