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

	
	template <class T>
	void fooT(const T& i)
	{
		std::cout << "this is lvalue\n";
	}

	//Для шаблонов это не всегда сработает
	template <class T>
	void fooT(T&& i)
	{
		std::cout << "this is rvalue\n";
	}
};

struct B
{
	B(A a)
	{
	}
};

struct C
{
	void inc(int& a)
	{
		a++;
	}
};

int foo()//RVO return value optimization
{
	return 42;//возвращаются напрямую, не создавая копий
}

int main()
{
	//rvalue - временный объект
	A a{};

	int ix = 5;
	//ix - переменная безссылочного типа на int
	//ix левый операнд
	//5 - временный объект rvalue (prvalue) чистое rvalue
	//5 правый операнд

	a.foo(ix);//передаем lvalue
	a.foo(5);//вызов rvalue
	a.foo(int(6)); //rvalue
	a.fooT(nullptr);//rvalue
	a.fooT("hello");//lvalue - строковый литерал
	//литерал представляет собой постоянное значение, у которого нет имени.


	C c;
	int i = 3;
	c.inc(i);

	//c.inc(3);//ошибка, мы не можем передавать rvalue в неконстантный lvalue
	// T& x = rvalue;
	// T& x = lvalue;
	//T&& x = lvalue; ошибка, так как мы не можем приравнять к какой-то ссылке lvalue

	int i8 = 8;
	//int&& i8_ref = i8;//ошибка rvalue не может быть присвоено lvalue
	//int&&(rvalue ссылка)
	//i8(lvalue)

	foo();//rvalue ссылка
	return 0;
}
