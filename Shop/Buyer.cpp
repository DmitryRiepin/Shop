#include "Buyer.h"

Buyer::Buyer(Deport* dep)
{	
	menuBuyer(dep);	
}

Buyer::~Buyer()
{
}

void Buyer::menuBuyer(Deport* dep)
{
c:
	system("cls");

	std::cout << "_____ ��������: _____\n\n";
	for (int i = 0; i < dep->nameShop.size(); ++i)
	{
		std::cout << dep->nameShop[i] << '\t' << dep->quantityShop[i] << " ��.\t" << dep->costShop[i] << " uah.\n";
	}
	std::cout << std::endl;

	getBuyer();
	std::cout << "********************\n";

	std::cout << "\t\t���� ����������.\n" <<
		"(1) �������� � �������.\n" <<
		"(2) ��������.\n" <<
		"(3) ������� �� �����.\n"<<
		"(4) �����.\n";
	
	int choise;
	std::cin >> choise;
	if (std::cin.fail() || choise > 4 || choise < 1)
	{
		std::cin.clear();
		std::cin.ignore(32657, '\n');
		std::cout << "������ ������ ���!\n";
		Sleep(500);
		goto c;
	}

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
		case 4:
		{
			break;
		}	
	}
}

void Buyer::addBuyer(Deport* dep)
{
	std::string name;
	double quantity;	

	std::cout << "������� ��������: ";
	std::cin.ignore();
	std::getline(std::cin, name);
d:
	std::cout << "������� ����������: ";
	std::cin >> quantity;
	if (std::cin.fail() || quantity <= 0)
	{
		std::cin.clear();
		std::cin.ignore(32657, '\n');
		std::cout << "������ �����!\n";
		goto d;
	}

	bool check = false;
	
	for (int j = 0; j < buyer->nameShop.size(); ++j)
	{
		if (buyer->nameShop[j] == name)
		{
			for (int i = 0; i < dep->nameShop.size(); ++i)
			{
				if (buyer->nameShop[j] == dep->nameShop[i] && dep->quantityShop[i] >= quantity)
				{
					buyer->quantityShop[j] += quantity;
					dep->quantityShop[i] -= quantity;
					buyer->costShop[i] += dep->costShop[i] * quantity;
					check = true;
				}	
				else if (buyer->nameShop[j] == dep->nameShop[i] && dep->quantityShop[i] < quantity)
				{
					check = true;
					std::cout << "�������� ����������!\n"; Sleep(500); break;
				}
			}
		}
		else { std::cout << "Whots wrong!\n"; Sleep(800); }
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
				break;
			}
			else if (dep->nameShop[i] == name && dep->quantityShop[i] < quantity)
			{
				std::cout << "�������� ����������!\n"; Sleep(500); break;
			}
			else if (i == dep->nameShop.size() - 1 && dep->nameShop[i] != name)
			{
				std::cout << "��� ������ ��������!\n";
				Sleep(500);
			}
		}
	}	
}

void Buyer::getBuyer()
{
	std::cout << "_____ �������: _____" << std::endl;
	for (int i = 0; i < buyer->nameShop.size(); ++i)
	{
		std::cout << buyer->nameShop[i] << '\t' << buyer->quantityShop[i] << " ��.\t" << buyer->costShop[i] << " uah.\n";
	}
}

void Buyer::paymant()
{
	system("cls");
	double total = 0;
	std::cout << "\t_____ ��� ��� _____\n" << std::endl;
	for (int i = 0; i < buyer->nameShop.size(); ++i)
	{
		total += buyer->costShop[i];
		std::cout << i+1 << ") " << buyer->nameShop[i] << '\t' << buyer->quantityShop[i] << " ��.\t" << buyer->costShop[i] << " uah.\n";
	}
	std::cout << "\n\t\t\t����� ��������: " << total << " uah.\n";
	system("pause");
}

void Buyer::returning(Deport* dep)
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
