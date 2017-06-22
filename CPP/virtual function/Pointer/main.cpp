#include "counten.h"
#include <iostream>

class Base
{
public:
	void show()
	{
		std::cout << "Base\n";
	}
};

class Child : public Base
{
public:
	void show()
	{
		std::cout << "Child\n";
	}
};

class Child2 : public Base
{
public:
	void show()
	{
		std::cout << "Child2\n";
	}
};

int main()
{
	Child child1;
	Child2 child2;
	Base* ptr;

	ptr = &child1;
	ptr->show();
	ptr = &child2;
	ptr->show();

	return 0;
}
