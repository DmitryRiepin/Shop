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
	std::cout << "\t\t���� ����������.\n" <<
		"(1) �������� � �������.\n" <<
		"(2) ��������.\n" <<
		"(3) ������� �� �����.\n";
	
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
		std::cout << "� ���� ��� ������ ������!";
		goto c;
	}
}

void Buyer::addBuyer(Depot* dep)
{
	std::string name;
	double quantity;	

	std::cout << "������� ��������: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "������� ����������: ";
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
			else { std::cout << "�������� ����������!\n"; }
		}
	}	
}

void Buyer::getBuyer()
{
	std::cout << "____�������____" << std::endl;
	for (int i = 0; i < buyer->nameShop.size(); ++i)
	{
		std::cout << buyer->nameShop[i] << '\t' << buyer->quantityShop[i] << " ��.\t" << buyer->costShop[i] << " uah.\n";
	}
}

void Buyer::paymant()
{
	system("cls");
	double total = 0;
	std::cout << "\t____��� ���____\n" << std::endl;
	for (int i = 0; i < buyer->nameShop.size(); ++i)
	{
		total += buyer->costShop[i];
		std::cout << i+1 << ") " << buyer->nameShop[i] << '\t' << buyer->quantityShop[i] << " ��.\t" << buyer->costShop[i] << " uah.\n";
	}
	std::cout << "\n\t\t\t����� ��������: " << total << " uah.\n";
	system("pause");
}

void Buyer::returning(Depot* dep)
{
	std::cout << "���������� �� ����� ��� �� ������.\n";
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
