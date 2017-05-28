#include "distance.h"
#include <iostream>

int main()
{
	Distance d1(1, 2);
	Distance d2(2, 3);
	Distance d3 = d1 + d2;
	

	d3++;
	Distance d4 = ++d3;

	d3.Print();
	d4.Print();

	return 0;
}
