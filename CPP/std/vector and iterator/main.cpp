#include <iostream>
#include <vector>
//#include "MyFunctor.hpp"
//#include "MyFunctorMax.h"
#include "SortBegin.h"
#include "SortEnd.h"
#include "WorkWithVector.h"
int main()
{
	std::vector<int> v1 = { 1, 2, 22, 5, 7 };
	MyFunctorMin<int> fMin(v1.begin(), v1.end());

	int b = *(fMin());

	MyFunctorMax<int> fMax(v1.begin(), v1.end());
	int c = *(fMax());

	std::cout << b << std::endl;
	std::cout << c << std::endl;

	SortBegin<int> sort(v1.begin(), v1.end());
	sort();

	SortEnd<int> sortE(v1.begin(), v1.end());
	sortE();

}
