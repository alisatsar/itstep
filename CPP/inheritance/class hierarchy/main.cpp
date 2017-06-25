#include "Employee.h"
#include <iostream>

int main()
{
	Manager m1;
	Manager m2;
	Scientist s1;
	Laborer l1;

	std::cout << std::endl;

	std::cout << "First manager: ";
	m1.GetData();

	std::cout << "Second manager: ";
	m2.GetData();

	std::cout << "Scientist: ";
	s1.GetData();

	std::cout << "Laborer: ";
	l1.GetData();

	std::cout << "First manager: ";
	m1.PutData();

	std::cout << "Second manager: ";
	m2.PutData();

	std::cout << "Scientist: ";
	s1.PutData();

	std::cout << "Laborer: ";
	l1.PutData();
}
