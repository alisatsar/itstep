#include <iostream>

class Base
{
public:
	virtual void Show() = 0; //чистая виртуальная функция
	void b()
	{
		std::cout << "b";
	}
};

class Derv1 : public Base
{
public:
	void Show()
	{
		std::cout << "Derv1\n";
	}
};

class Derv2 : public Base
{
public:
	void Show()
	{
		std::cout << "Derv2\n";
	}
};

int main()
{
	//Base bas; // you cannot create an object of an abstract class
	Base* arr[2];	//массив указателей на базовый класс

	Derv1 dv1;
	Derv2 dv2;

	arr[0] = &dv1;	//заносим адрес dv1 в массив
	arr[1] = &dv2;	//заносим адрес dv2 в массив

	arr[0]->Show();
	arr[1]->Show();
	return 0;
}
