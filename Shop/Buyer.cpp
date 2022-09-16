#include "Buyer.h"

Buyer::Buyer(Depot* dep)
{	
	menuBuyer(dep);	
}

Buyer::~Buyer()
{
}

void Buyer::menuBuyer(Depot* dep)
{
	system("cls");

	std::cout << "_____Products_____\n\n";
	for (int i = 0; i < dep->nameShop.size(); ++i)
	{
		std::cout << dep->nameShop[i] << '\t' << dep->quantityShop[i] << '\t' << dep->costShop[i] << "uah.\n";
	}
	std::cout << std::endl;

	getBuyer();
	std::cout << "********************\n";
c:
	std::cout << "\t\tМеню покупателя.\n" <<
		"(1) Добавить в карзину.\n" <<
		"(2) Оплатить.\n" <<
		"(3) Вернуть на полки.\n";
	
	int choise;
	std::cin >> choise;

	switch (choise)
	{
	case 1:
	{
		addBuyer(dep);
		menuBuyer(dep);
		break;
	}
	case 2:
	{
		paymant();
		break;
	}
	case 3:
	{
		returning(dep);
		break;
	}
	default:
		std::cout << "В меню нет такого пункта!";
		goto c;
	}
}

void Buyer::addBuyer(Depot* dep)
{
	std::string name;
	double quantity;	

	std::cout << "Введите название: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Введите количество: ";
	std::cin >> quantity;

	bool check = false;
	
	for (int j = 0; j < buyer->nameShop.size(); ++j)
	{
		if (buyer->nameShop[j] == name)
		{
			for (int i = 0; i < dep->nameShop.size(); ++i)
			{
				if (buyer->nameShop[j] == dep->nameShop[i])
				{
					buyer->quantityShop[j] += quantity;
					dep->quantityShop[i] -= quantity;
					buyer->costShop[i] += dep->costShop[i] * quantity;
					check = true;
				}				
			}
		}
		else { std::cout << "Whots wrong!\n"; }
	}

	if (check == false)
	{
		for (int i = 0; i < dep->nameShop.size(); ++i)
		{

			if (dep->nameShop[i] == name && dep->quantityShop[i] >= quantity)
			{
				buyer->nameShop.push_back(dep->nameShop[i]);
				buyer->quantityShop.push_back(quantity);
				dep->quantityShop[i] -= quantity;
				buyer->costShop.push_back(dep->costShop[i] * quantity);
			}
			else { std::cout << "Неверное количество!\n"; }
		}
	}	
}

void Buyer::getBuyer()
{
	std::cout << "____Корзина____" << std::endl;
	for (int i = 0; i < buyer->nameShop.size(); ++i)
	{
		std::cout << buyer->nameShop[i] << '\t' << buyer->quantityShop[i] << " шт.\t" << buyer->costShop[i] << " uah.\n";
	}
}

void Buyer::paymant()
{
	system("cls");
	double total = 0;
	std::cout << "\t____Ваш чек____\n" << std::endl;
	for (int i = 0; i < buyer->nameShop.size(); ++i)
	{
		total += buyer->costShop[i];
		std::cout << i+1 << ") " << buyer->nameShop[i] << '\t' << buyer->quantityShop[i] << " шт.\t" << buyer->costShop[i] << " uah.\n";
	}
	std::cout << "\n\t\t\tВсего оплачено: " << total << " uah.\n";
	system("pause");
}

void Buyer::returning(Depot* dep)
{
	std::cout << "Возвращяем на полки все из козины.\n";
	getBuyer();
	std::cout << std::endl;

	for (int i = 0; i < buyer->nameShop.size(); ++i)
	{
		for (int j = 0; j < dep->nameShop.size(); ++j)
		{
			if (buyer->nameShop[i] == dep->nameShop[j])
			{
				dep->quantityShop[j] += buyer->quantityShop[i];
				buyer->quantityShop[i] = 0;
			}
		}
	}
	system("pause");
}
