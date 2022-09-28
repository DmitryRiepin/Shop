#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Deport.h"
#include "Seller.h"
#include "Buyer.h"


void menu(Deport* dep);

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Deport dep(1);

	menu(&dep);

	dep.saveChenge(); //Сохраняем изменения в Файле хранения.
		
}

void menu(Deport* dep)
{
a:
	system("cls");
	int mainMenu;

	std::cout << "\t\tОсновное меню магазина.\n" <<
		"Нажмите (1), если Вы продавец.\n" <<
		"Нажмите (2), если Вы покупатель.\n" <<
		"Нажмите (3), для Выхода.\n";
	std::cin >> mainMenu;
	if (std::cin.fail() || mainMenu > 3 || mainMenu < 1)
	{
		std::cin.clear();
		std::cin.ignore(32657, '\n');
		std::cout << "Такого пункта нет!\n";
		Sleep(500);
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
	
	}
}
