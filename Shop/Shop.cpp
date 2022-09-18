#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Depot.h"
#include "Seller.h"
#include "Buyer.h"


void menu(Depot* dep);
void readF(Depot* dep, std::ifstream& read);
void saveCheng(Depot* dep);

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream read;
	
	Depot *dep = new Depot;

	readF(dep, read);

	menu(dep);

	saveCheng(dep);
    
}

void menu(Depot* dep)
{
	system("cls");
	int mainMenu;
a:
	std::cout << "\t\tОсновное меню магазина.\n" <<
		"Нажмите (1), если Вы продавец.\n" <<
		"Нажмите (2), если Вы покупатель.\n" <<
		"Нажмите (3) для Выхода.\n";
	std::cin >> mainMenu;
	if (std::cin.fail() || mainMenu > 3 || mainMenu < 1)
	{
		std::cin.clear();
		std::cin.ignore(32657, '\n');
		std::cout << "Такого пункта нет!\n";
		goto a;
	}

	switch (mainMenu)
	{
	case 1:
	{
		Seller sel(dep);
				
		menu(dep);
		break;
	}
	case 2:
	{
		Buyer buy(dep);
		menu(dep);
		break;
	}
	case 3:		{break; }

	default:
		std::cout << "Такого пункта нет!\n";
		menu(dep);
		break;
	}
}

void readF(Depot* dep, std::ifstream& read)
{
	read.open("Test.csv");
	if (!read)
	{
		std::cout << "Sorry file not read\n";
	}

	std::vector<std::string> reading;

	while (read)
	{
		std::string str;
		std::getline(read, str);
		reading.push_back(str);
	}

	read.close();

	for (int i = 1; i < reading.size()-1; ++i)
	{
		std::string read1;
		int count = 0;

		for (int j = 0; j <= reading[i].size(); ++j)
		{
			char ch = reading[i][j];
			
			if (ch == ';' && count == 0)
			{
				dep->nameShop.push_back(read1);				
				read1 = "";
				++count;
			}
			else if (ch == ';' && count == 1)
			{
				dep->quantityShop.push_back(stod(read1));
				read1 = "";
				++count;
			}
			else if (ch == '\0')
			{
				dep->costShop.push_back(stod(read1));
				read1 = "";				
			}

			if (ch != ';')
			{
				read1 += ch;
			}
		}
	}
}

void saveCheng(Depot* dep)
{
	std::ofstream save;
	save.open("Test.csv");

	if(!save)
	{
	std::cout <<"Sorry file not create\n";
	}

	save << "Name;" << "Qwantity;" << "Cost\n";

	for (int i = 0; i < dep->nameShop.size(); ++i)
	{
		save << dep->nameShop[i] << ';' << dep->quantityShop[i] << ';' << dep->costShop[i] << std::endl;
	}
	save.close();
}