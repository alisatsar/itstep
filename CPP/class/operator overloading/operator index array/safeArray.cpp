#include <iostream>
#include "safeArray.h"

void SafeArray::Putel(int n, int elvalue)
{
	if (n < 0 || n >= LIMIT)
	{
		std::cout << "\nThe wrong index!"; 
		exit(1);
	}
	array[n] = elvalue;
}

int SafeArray::Getel(int n) const
{
	if (n < 0 || n >= LIMIT)
	{
		std::cout << "\nThe wrong index!";
		exit(1);
	}
	return array[n];
}

int& SafeArray::access(int n)
{
	if (n < 0 || n >= LIMIT)
	{
		std::cout << "\nThe wrong index!";
		exit(1);
	}
	return array[n];
}

int& SafeArray::operator[](int n)
{
	if (n < 0 || n >= LIMIT)
	{
		std::cout << "\nThe wrong index!";
		exit(1);
	}
	return array[n];
}
