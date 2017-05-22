#include "distance.h"
#include <iostream>

int main()
{
	Distance d1 = Read();
	Distance d2 = Read();

	Distance d3 = Summ(d1, d2);
	Print(d3);

	d1 = Read();
	d2 = Read();

	d3 = Diff(d1, d2);
	Print(d3);

	return 0;
}
