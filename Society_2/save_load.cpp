//#include<iostream>
//#include<vector>
//#include<string>
//#include<ctime>
#include<fstream>
#include"Society_2.h"

/*ios::trunc is true when ios::out
ios::trunc is false when ios::ate || ios::app || ios:in*/

extern std::string path1;//used when we'll need other path
extern std::string path2;

void save_data(const std::vector<std::vector<Relative>> &soc) {

	::Relative::Translation temp_trans;

	int length_trans = sizeof(::Relative::Translation);
	size_t length_size = sizeof(size_t), size = 0;

	std::ofstream fout;
	fout.open(path2, std::ios::binary);

	if (!fout.is_open())
	{
		std::cout << "Error of opening!!!";
	}
	else
	{
		size = soc.size();
		fout.write(reinterpret_cast<char*>(&size), length_size);

		for (int i = 0; i < soc.size(); i++)
		{
			size = soc[i].size();
			fout.write(reinterpret_cast<char*>(&size), length_size);

			if (!soc[i].size())
				continue;

			for (int j = 0; j < soc[i].size(); j++) {
				temp_trans = soc[i][j];
				fout.write(reinterpret_cast<char*>(&temp_trans), length_trans);
			}
		}
	}
	fout.close();
}

void load_data(std::vector<std::vector<Relative>> &soc) {

	if (soc.size()) {
		for (int c = 0; c < soc.size(); c++)
			soc[c].clear();

		soc.clear();
	}

	::Relative::Translation temp_trans;
	::Relative temp_rel;

	int length_trans = sizeof(::Relative::Translation);
	size_t length_size = sizeof(size_t), size = 0;

	std::ifstream fin;
	fin.open(path2);//, std::ios::binary

	if (!fin.is_open()) {
		std::cout << "Error of opening!!!";
	}
	else {
		fin.read(reinterpret_cast<char*>(&size), length_size);

		std::vector<Relative> temp_vec;
		while (size--)
			soc.push_back(temp_vec);

		for (int i = 0; i < soc.size(); i++) {
			fin.read(reinterpret_cast<char*>(&size), length_size);

			while (size--)
				soc[i].push_back(temp_rel);

			if (!soc[i].size())
				continue;

			for (int j = 0; j < soc[i].size(); j++) {
				fin.read(reinterpret_cast<char*>(&temp_trans), length_trans);
				soc[i][j] = temp_trans;
			}
		}
	}

	fin.close();
}