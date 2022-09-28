#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#pragma once
class Deport
{
public:
	std::vector<std::string> nameShop;
	std::vector<double> quantityShop;
	std::vector<double> costShop;
	
public:

	Deport(); // Конструктор по умолчанию, для создания корзины покупателя.

	Deport(int num); // Конструктор для создания склада.
	
	~Deport();

	void saveChenge();
			
};

