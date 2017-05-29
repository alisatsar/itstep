#include <iostream>
#include "example.h"

Counter::Counter():count(0)
{
}

Counter::Counter(int c)
{
	count = c;
}

unsigned int Counter::GetCount()
{
	return count;
}

Counter Counter::operator++()
{
	return Counter(++count);
}

Counter Counter::operator++(int)
{
	return Counter(count++);
}
