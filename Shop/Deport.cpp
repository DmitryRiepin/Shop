#include "Deport.h"

Deport::Deport()
{

}

Deport::Deport(int num)
{
	std::ifstream read;

	read.open("Test.csv");
	if (!read)
	{
		std::cout << "Sorry file not read\n";
	}

	std::vector<std::string> reading;

	while (read)
	{
		std::string str;
		std::getline(read, str);
		reading.push_back(str);
	}

	read.close();

	for (int i = 1; i < reading.size() - 1; ++i)
	{
		std::string read1;
		int count = 0;

		for (int j = 0; j <= reading[i].size(); ++j)
		{
			char ch = reading[i][j];

			if (ch == ';' && count == 0)
			{
				nameShop.push_back(read1);
				read1 = "";
				++count;
			}
			else if (ch == ';' && count == 1)
			{
				quantityShop.push_back(stod(read1));
				read1 = "";
				++count;
			}
			else if (ch == '\0')
			{
				costShop.push_back(stod(read1));
				read1 = "";
			}

			if (ch != ';')
			{
				read1 += ch;
			}
		}
	}
}

Deport::~Deport()
{
	
}

void Deport::saveChenge()
{
	std::ofstream save;
	save.open("Test.csv");

	if (!save)
	{
		std::cout << "Sorry file not create\n";
	}

	save << "Название;" << "Количество;" << "Цена\n";

	for (int i = 0; i < nameShop.size(); ++i)
	{
		save << nameShop[i] << ';' << quantityShop[i] << ';' << costShop[i] << std::endl;
	}
	save.close();
}




