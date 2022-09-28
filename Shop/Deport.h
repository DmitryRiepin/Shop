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

	Deport(); // ����������� �� ���������, ��� �������� ������� ����������.

	Deport(int num); // ����������� ��� �������� ������.
	
	~Deport();

	void saveChenge();
			
};

