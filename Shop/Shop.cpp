#include <iostream>
#include "Depot.h"
#include "Seller.h"
#include "Buyer.h"

void menu(Depot* dep);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Rus");

    Depot *dep = new Depot;

	menu(dep);

	dep->~Depot();
    
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