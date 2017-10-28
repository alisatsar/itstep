#include <iostream>

struct A
{
	A()
	{
		std::cout << "A default constructor." << std::endl;
	}

	A(const int& i)
	{
		std::cout << i << std::endl;
	}

	void foo(const int& i)
	{
		std::cout << "this is lvalue\n";
	}

	//двойна ссылка, rvalue ссылка
	void foo(int&& i)
	{
		std::cout << "this is rvalue\n";
	}
};

int&& MyMoveInt(int& i)
{
	return static_cast<int&&>(i);
}

int main()
{	
	A a{};
	int i3 = 3;
	a.foo(i3);//принимает lvalue
	a.foo(std::move(i3));//принимает rvalue
	//std::move - Конвектор, который превращает rvalue
	//на самом деле std::move Делает xvalue

	int i = 11;
	static_cast<int&&>(i);//преобразование lvalue в rvalue

	a.foo(static_cast<int&&>(i));//конструктор принимает rvalue
	a.foo(static_cast<int&>(i));//преобразования нет, просто явно указываем тип lvalue

	return 0;
}
