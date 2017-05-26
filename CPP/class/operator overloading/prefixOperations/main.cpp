#include <iostream>
#include "counter.h"

int main()
{
	Counter c1;
	Counter c2;

	std::cout << "\nc1 = " << c1.GetCount();
	std::cout << "\nc2 = " << c2.GetCount();

	++c1;
	++c2;
	++c2;

	std::cout << "\nc1 = " << c1.GetCount();
	std::cout << "\nc2 = " << c2.GetCount();

	Object o1;
	Object o2;

	std::cout << "\no1 = " << o1.GetObject();
	std::cout << "\no2 = " << o2.GetObject();

	++o1;
	o2 = ++o1;
	

	std::cout << "\no1 = " << o1.GetObject();
	std::cout << "\no2 = " << o2.GetObject();

	
	return 0;
}
