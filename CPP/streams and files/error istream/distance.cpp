#include <iostream>
#include <string>
#include <cstdlib>		//для atoi(), atof()

int isFeet(std::string);

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0.0)
	{
	}

	Distance(int ft, float in) : feet(ft), inches(in)
	{
	}

	void ShowDist()
	{
		std::cout << feet << "\'=" << inches << '\"';
	}

	void GetDistance()
	{
		std::string instr;		//входная строка

		while (true)
		{
			std::cout << "\n\nEnter feet: ";
			std::cin.unsetf(std::ios::skipws);		//не пропускать разделители
			std::cin >> instr;

			if (isFeet(instr))
			{
				std::cin.ignore(10, '\n');	//удалить символы, включая \n
				feet = std::atoi(instr.c_str()); // перевести значение в целочисленное
				break;
			}

			std::cin.ignore(10, '\n');
			std::cout << "Feets should be integer < 1000\n";
		}

		while (true)
		{
			std::cout << "Enter inches: ";
			
			std::cin.unsetf(std::ios::skipws);		//не пропускать разделители
			std::cin >> inches;

			if (inches >= 12.0 || inches < 0.0)
			{
				std::cout << "Inches should be anong 0.0 and 11.99\n";
				std::cin.clear(std::ios::failbit); //исскуственно установить флаг ошибки
			}

			if (std::cin.good())		//все ли хорошо с cin(проверка)
			{
				std::cin.ignore(10, '\n');		//очистить символы с разделителем
				break;
			}
			
			std::cin.clear();		//ошибка, очистить статус ошибки
			std::cin.ignore(10, '\n');		//очистить символы с разделителем
			std::cout << "The wrong input: ";
		}
	}
};

int isFeet(std::string str)
{
	int slen = str.size();

	if (slen == 0 || slen > 5)
	{
		return 0;
	}

	for (int i = 0; i < slen; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
		{
			return 0;
		}
	}

	double n = atof(str.c_str());	//перевод в double

	if (n <-999.0 || n > 999.0)
	{
		return 0;
	}
	return 1;
}

int main()
{
	Distance d;
	char ans;

	do
	{
		d.GetDistance();

		std::cout << "\nDistance: ";
		d.ShowDist();
		std::cout << "\nTry again: (y/n)?";
		std::cin >> ans;
		std::cin.ignore(10, '\n');
	} while (ans != 'n');

	return 0;
}
