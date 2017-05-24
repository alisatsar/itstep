#include <iostream>

class A
{
	const int a;

public:
	A(int a) :
		a(a)
	{
	}
};

A global(1);

class B
{
	A& a;
public:
	B():a(global)
	{
	}

	B(A& a) : a(a)
	{
	}
};

int main()
{
	A a1(100);
	B b(al);
	return 0;
}
