#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#pragma once
class Depot
{
public:
	std::vector<std::string> nameShop;
	std::vector<double> quantityShop;
	std::vector<double> costShop;
	
public:

	Depot();
	~Depot();
		
};

