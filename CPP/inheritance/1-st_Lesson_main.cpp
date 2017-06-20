#include <iostream>

class A
{
public:
	void MethodA()
	{
		std::cout << "Method A\n";
	}
protected:
	void MethodC()
	{
		std::cout << "Method X\n";
	}
};

class B : public A
{
public:
	void MethodB()
	{
		std::cout << "Method B\n";
		MethodC();
	}
};

struct C : public B
{

};

struct D : C
{

};

int main()
{
	A a;
	a.MethodA();
	

	B b;
	b.MethodA();
	b.MethodB();

}
