
//#include<iostream>
//#include<vector>
//#include<string>
//#include<ctime>
//#include<fstream>
#include"Society_2.h"

//#define DE1

std::ostream& operator<<(std::ostream& os, const Human& obj) {
	obj << os;
	return os;
}

std::istream& operator>>(std::istream& is, Human& obj) {
	obj >> is;
	return is;
}

std::istream& bad_insert(std::istream& is) {
	is.clear();
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return is;
}

void get_soc_info(std::vector<std::vector<Relative>>& soc) {
	size_t length = soc.size();

	for (int f = 0; f < length; f++) {
		std::cout << "\tFamily # " << f + 1 << ":" << std::endl;

		for (int r = 0; r < soc[f].size(); r++) {
			std::cout << "\t\t" << r + 1 << ") " << soc[f][r];
		}
	}
}

#ifndef DE1
void insert_or_erase_fam(std::vector<std::vector<Relative>>& soc, const int& index, const int& quantity, const options& what) {

	std::vector<std::vector<Relative>>::iterator it;

	it = soc.begin();
	it += index;

	if (what == ADD_SOC)
	{
		std::vector<std::vector<Relative>> temp_soc(quantity);
		soc.insert(it, temp_soc.begin(), temp_soc.end());
	}
	else if (what == ADD_FAM)
	{
		std::vector<Relative> temp_fam(quantity);
		soc.insert(it, temp_fam);
	}
	else if (what == ER_FAM)
	{
		soc.erase(it, it + quantity);
	}
	std::cout << "\tsoc.size()\t" << soc.size() << std::endl;
}

void insert_or_erase_rel(std::vector<std::vector<Relative>> &soc, const int& fam_index, const int& rel_index, const int& quantity, const options& what) {

	std::vector<Relative>::iterator it;
	it = soc[fam_index].begin();
	it += rel_index;

	if (what == ADD_REL)
	{
		Relative temp;
		for (size_t i = 0; i < quantity; i++) { soc[fam_index].push_back(temp); }
	}
	else if (what == ER_REL)
	{
		soc[fam_index].erase(it, it + quantity);
	}

	std::cout << "\tsoc[" << fam_index << "].size()\t" << soc[fam_index].size() << std::endl;
}

void msg() {
	std::cout << "\t\tSomething wrong\n\t\tPlease, try again\n";
}

bool check_lim(std::vector<std::vector<Relative>> &soc, const int& fam_index, const int& rel_index) {
	if (fam_index > soc.size()) {
		msg();
		return false;
	}
	else if (rel_index > soc[fam_index].size()) {
		msg();
		return false;
	}
	return rel_index <= soc[fam_index].size() || fam_index <= soc.size();
}

#endif // !DE1