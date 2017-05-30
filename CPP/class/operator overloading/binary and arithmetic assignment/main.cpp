#include "example.h"
#include <iostream>

int main()
{
	Distance distance1;
	distance1.GetList();

	Distance distance2(1, 3.3);

	distance1.ShowList();
	distance2.ShowList();

	if (distance1 < distance2)
	{
		std::cout << "distance1 < distance2" << std::endl;
	}
	else if (distance1 == distance2)
	{
		std::cout << "distance1 == distance" << std::endl;
	}
	else
	{
		std::cout << "distance1 > distance2" << std::endl;
	}

	Distance distance3;
	distance3 += distance1;

	distance3.ShowList();

	return 0;
}
