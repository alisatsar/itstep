#pragma once

class Counter
{
private:
	unsigned int m_count;

public:
	Counter();
	unsigned int GetCount();
	void operator++();
};

class Object
{
private:
	unsigned int m_object;

public:
	Object();
	Object(unsigned int object);
	unsigned int GetObject();
	Object operator++();
};
