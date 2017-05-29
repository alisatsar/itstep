#include "Distance.h"
#include <iostream>

int main()
{
	Distance d1;
	Distance d2;

	std::cout << "Enter First: ";
	std::cin >> d1;

	std::cout << "enter secont: ";
	std::cin >> d2;

	Distance summ = d1 + d2;
	std::cout << "Summ: " << summ << "\n";
	summ = summ + 1;		//неяснове преобразование поэтому реализуем через функцию Distance Distance::operator+(int feet), которая явно принимает инт, а не класс
	summ =  2 + summ;
	return 0;
}
