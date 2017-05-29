#include "example.h"
#include <iostream>

int main()
{
	Counter c1;
	Counter c2;

	std::cout << "\nc1 = " << c1.GetCount();
	std::cout << "\nc2 = " << c2.GetCount();

	++c1;
	c2 = ++c1;

	std::cout << "\nc1 = " << c1.GetCount();
	std::cout << "\nc2 = " << c2.GetCount();

	c2 = c1++;		//сначала присваивание с2 значения с1, а потом увеличение с1 на 1

	std::cout << "\nc1 = " << c1.GetCount();
	std::cout << "\nc2 = " << c2.GetCount() << std::endl;

	return 0;
}
