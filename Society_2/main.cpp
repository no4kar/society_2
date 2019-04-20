#include<iostream>
#include<vector>
//#include<string>
//#include<ctime>
//#include<fstream>
#include"Society_2.h"

std::string path2 = "soc.txt";

int main() {
	std::vector<std::vector<Relative>> soc;
	int relative, family, choice = 1;

	do
	{	switch (--choice)
		{
		case ADD_FAM:
			do
			{	std::cout << "\tDefinde the place where will be new family?\t";
				std::cin >> family;
				std::cout << "\tHow many relative will be in new family?\t";
				std::cin >> relative;
			} while (!check_lim(soc, INDEX(family), INDEX(1)) && bool(std::cin));

			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}

			insert_or_erase_fam(soc, INDEX(family), relative, ADD_FAM);
			break;

		case ADD_REL:
			do
			{	std::cout << "\tWhat is the number of family?\t# ";
				std::cin >> family;
			} while (!check_lim(soc, INDEX(family), INDEX(1)) && bool(std::cin));

			std::cout << "\tHow many relatives do you want to add?\t";
			std::cin >> relative;

			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}

			insert_or_erase_rel(soc, INDEX(family), 0, relative, ADD_REL);
			break;

		case SET_REL:
			do
			{	std::cout << "\tWhat is the number of family?\t# ";
				std::cin >> family;
				std::cout << "\tWhose data's do you want to change?(relative's number)\t# ";
				std::cin >> relative;
				
			} while (!check_lim(soc, INDEX(family), INDEX(relative)) && bool(std::cin));
			
			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}

			soc[INDEX(family)][INDEX(relative)].set_info();
			break;

		case SAVE_DATA:
			save_data(soc);
			break;

		case LOAD_DATA:
			load_data(soc);
			break;

		case ADD_SOC:
			if (soc.size()) {
				soc.clear();
			}
			std::cout << "\tHow many familys do you want creat?\n\t";
			std::cin >> family;
			if (!family) { break; }
			insert_or_erase_fam(soc, 0, family, ADD_SOC);
			break;

		case GET_INFO_ALL_FAM:
			get_soc_info(soc);
			break;

		default:
			std::cout << "\n\nSorry. What do you mean? This is all what I have\n";
			get_soc_info(soc);

			break;
		}
		std::cout << "\n1.Creat a new society\n2.Add family;\n3.Add relatives;\n4.Set relative;\n"
			<< "5.Get info about all familys;\n6.Save data;\n7.Load data;\t(enter '*' for ending)\n\t# ";

	} while (std::cin >> choice);

	std::cout << "One is glad to be of service\n";
	system("pause");
	return 0;
}
