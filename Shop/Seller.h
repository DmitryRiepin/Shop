#include<iostream>
#include<string>
#include <vector>
#include <Windows.h>
#include "Deport.h"

#pragma once


class Seller 
{
private:
	const std::string name = "Dima";
	const int id = 1234;

public:
	Seller() = delete;
	Seller(Deport *dep);
	~Seller();

	std::string getName();
	int getId();

	void menuSell(Deport* dep);

	void addProduct(Deport* dep);
	void delProduct(Deport* dep);
};

