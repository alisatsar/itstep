#include <iostream>
#include "counter.h"

Counter::Counter() :m_count(0)
{
	std::cout << "Construction\n";
}

unsigned int Counter::GetCount()
{
	return m_count;
}

void Counter::operator++()
{
	++m_count;
}

Object::Object() : m_object(0)
{
	std::cout << "\nConstructor";
}

Object::Object(unsigned int object) : m_object(object)
{
	std::cout << "\nConstructor with arguments";
}

unsigned int Object::GetObject()
{
	return m_object;
}

/*Object Object::operator++()
{
	++m_object;
	Object buff;
	buff.m_object = m_object;
	return buff;
}*/

Object Object::operator++()
{
	++m_object;
	return Object(m_object);
}
