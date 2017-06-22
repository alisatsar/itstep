#include "Distance.h"
#include <iostream>

int main()
{
	DistanceSign alpha;
	alpha.GetDistance();

	DistanceSign beta(11, 6.23F);

	DistanceSign gamma(100, 5.5F, neg);

	std::cout << "\nA = ";
	alpha.ShowDistance();
	std::cout << "\nB = ";
	beta.ShowDistance();
	std::cout << "\nC = ";
	gamma.ShowDistance();

	return 0;
}
