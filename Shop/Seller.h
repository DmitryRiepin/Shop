#include<iostream>
#include<string>
#include <vector>
#include "Depot.h"

#pragma once


class Seller 
{
private:
	const std::string name = "Dima";
	const int id = 1234;



public:
	Seller() = delete;
	Seller(Depot *dep);
	~Seller();

	std::string getName();
	int getId();

	void menuSell(Depot* dep);

	void addProduct(Depot* dep);
	void delProduct(Depot* dep);


	//void getProduct(Depot* dep);

};

