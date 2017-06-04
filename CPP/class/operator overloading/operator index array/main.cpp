#include "safeArray.h"
#include <iostream>


int main()
{
	SafeArray sa1;

	for (int j = 0; j < LIMIT; j++)
	{
		sa1.access(j) = (j * 10);
	}

	for (int j = 0; j < LIMIT; j++)
	{
		std::cout << "Element" << j << "equal " << sa1[j] << std::endl;
	}

	return 0;
}
