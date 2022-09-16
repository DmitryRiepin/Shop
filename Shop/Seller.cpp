#include "Seller.h"


Seller::Seller(Depot* dep)
{
	std::string m_name;
	int m_id;
	std::cin.ignore();
	std::cout << "������� ���: ";
	std::getline(std::cin, m_name);
	std::cout << "������� ������: ";
	std::cin >> m_id;

	if (m_name == getName() && m_id == getId())
	{
		menuSell(dep);
	}
	else { std::cout << "�������� ������������!\n"; }

}


Seller::~Seller()
{
}

std::string Seller::getName()
{
	return name;
}

int Seller::getId()
{
	return id;
}

void Seller::menuSell(Depot* dep)
{
	system("cls");

	std::cout << "_____Deport_____\n\n";
	for (int i = 0; i < dep->nameShop.size(); ++i)
	{
		std::cout << dep->nameShop[i] << '\t' << dep->quantityShop[i] << '\t' << dep->costShop[i] << " uah.\n";
	}
	std::cout << std::endl;

	int choice = 0;
	std::cout << "\t\t������ ���� " << name << "!\n";
	std::cout << "\n(1) �������� ��������.\n" <<
		"(2) ������� ��������.\n" <<
		"(3) Exit\n";
	std::cin >> choice;
	
	switch (choice)
	{
	case 1:
	{
		addProduct(dep);
		menuSell(dep);
		break;
	}
	case 2:
	{
		delProduct(dep);
		menuSell(dep);
		break;
	}
	case 3:	break;
	
	}

}

void Seller::addProduct(Depot* dep)
{
	std::string name;
	double quantity;
	double cost;

	std::cout << "������� ��������: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	bool chack = false;
	for (int i = 0; i < dep->nameShop.size(); ++i)
	{
		if (dep->nameShop[i] == name)
		{
			std::cout << "������� ����������: ";
			std::cin >> quantity;
			dep->quantityShop[i] += quantity;
			chack = true;
		}
	}
	
	if(chack == false)
	{
		std::cout << "������� ����������: ";
		std::cin >> quantity;
		std::cout << "������� ����: ";
		std::cin >> cost;

	dep->nameShop.push_back(name);
	dep->quantityShop.push_back(quantity);
	dep->costShop.push_back(cost);
	}
}

void Seller::delProduct(Depot* dep)
{
	std::string name;
	double quantity;
	double cost;
	bool check = false;
b:
	std::cout << "������� ����� ���������? (�� - 1, ��� - 0)\n";
	std::cin >> check;
	if (std::cin.fail() || check > 1 || check < 0)
	{
		std::cin.clear();
		std::cin.ignore(32657, '\n');
		std::cout << "������ 1 ��� 0!\n";
		goto b;
	}

	std::cout << "������� �������� ������: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	
	for (int i = 0; i < dep->nameShop.size();++i )
	{
		if (dep->nameShop[i] == name)
		{
			if (check == true)
			{
				dep->nameShop.erase(dep->nameShop.begin() + i);
				dep->quantityShop.erase(dep->quantityShop.begin() + i);
				dep->costShop.erase(dep->costShop.begin() + i);
				break;
			}
			
			std::cout << "������� �������: ";
			std::cin >> quantity;
			if (quantity <= dep->quantityShop[i])
			{
				dep->quantityShop[i] -= quantity;
			}
			else
			{
				std::cout << "��� ������� ������!\n";
			}		
			
		}
		
	}
}


