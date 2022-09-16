#include <iostream>
#include <vector>
#include <string>
#include "Depot.h"



#pragma once
class Buyer 
{
private:
	
	Depot* buyer = new Depot;

public:
	Buyer() = delete;
	Buyer(Depot* dep);
	~Buyer();

	void menuBuyer(Depot* dep);

	void addBuyer(Depot* dep);
	void getBuyer();

	void paymant();

	void returning(Depot* dep);

};

