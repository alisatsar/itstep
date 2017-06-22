#pragma once
#include <iostream>

class Counter
{
protected:
	unsigned int count;
public:
	Counter() : count(0)
	{
		std::cout << "Parent\n";
	}

	Counter(int c) : count(c)
	{
	}

	unsigned int GetCount() const
	{
		return count;
	}

	Counter operator++()
	{
		return Counter(++count);
	}
};

class CountDn : public Counter
{
public:
	CountDn() :Counter()
	{
		std::cout << "Child\n";
	}

	CountDn(int c) :Counter(c)
	{
		std::cout << "Child\n";
	}
	Counter operator--()
	{
		return CountDn(--count);
	}
};
