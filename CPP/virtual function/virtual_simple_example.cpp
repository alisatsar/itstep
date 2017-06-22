#include "counten.h"
#include <iostream>

class Base
{
public:
	virtual void show()
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
	Child child1;	// Объект производного класса 1 
	Child2 child2;	// Объект производного класса 2 
	Base* ptr;	// Указатель на базовый класс 

	ptr = &child1;	// Адрес dv1 занести в указатель 
	ptr->show();	// Выполнить show() 
	ptr = &child2;	// Адрес dv2 занести в указатель 
	ptr->show();	// Выполнить show() 

	return 0;
}
