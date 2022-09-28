#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Deport.h"



#pragma once
class Buyer 
{
private:
	
	Deport* buyer = new Deport;

public:
	Buyer() = delete;
	Buyer(Deport* dep);
	~Buyer();

	void menuBuyer(Deport* dep);

	void addBuyer(Deport* dep);
	void getBuyer();

	void paymant();

	void returning(Deport* dep);

};

