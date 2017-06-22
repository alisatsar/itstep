#pragma once
#include <iostream>

class Stack
{
protected:
	enum { MAX = 3 };
	int st[MAX];
	int top;
public:
	Stack()
	{
		top = -1;
	}

	void Push(int var)
	{
		st[++top] = var;
	}

	int Pop()
	{
		return st[top--];
	}
};

class Stack2 : public Stack
{
public:
	void Push(int var)
	{
		if (top >= MAX - 1)
		{
			std::cout << "\nError\n";
			exit(1);
		}
		Stack::Push(var);
	}

	int Pop()
	{
		if (top < 0)
		{
			std::cout << "\nError\n";
			exit(1);
		}
		return Stack::Pop();
	}
};
