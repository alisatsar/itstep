#include "distance.h"
#include <iostream>


int main()
{
	float meters;
	Distance dis1 = 1.23F;

	std::cout << "\ndis1\n";
	std::cout << dis1;

	meters = dis1;

	meters = static_cast<float>(dis1);

	std::cout << meters;

	return 0;
}
