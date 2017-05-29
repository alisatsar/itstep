#pragma once

class Counter
{
private:
	unsigned int count;
		
public:
	Counter();
	Counter(int c);

	unsigned int GetCount();
	Counter operator++();
	Counter operator++(int);
};
