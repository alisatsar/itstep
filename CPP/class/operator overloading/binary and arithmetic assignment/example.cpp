include <iostream>
#include "example.h"
#include <cstring>

Distance::Distance() :m_feet(0), m_inches(0)
{
}

Distance::Distance(int feet, float inches) : m_feet(feet), m_inches(inches)
{
}

void Distance::GetList()
{
	std::cout << "Enter feet: ";
	std::cin >> m_feet;
	std::cout << "Enter inches: ";
	std::cin >> m_inches;
}

void Distance::ShowList()
{
	std::cout << m_feet << std::endl;
	std::cout << m_inches << std::endl;
}

bool Distance::operator < (Distance distance) const
{
	float inches1 = m_feet * 12 + m_inches;
	float inches2 = distance.m_feet * 12 + distance.m_inches;

	return (inches1 < inches2) ? true : false;
}

bool Distance::operator == (Distance distance) const
{
	float inches1 = m_feet * 12 + m_inches;
	float inches2 = distance.m_feet * 12 + distance.m_inches;

	return (inches1 == inches2) ? true : false;
}

void Distance::operator += (Distance const& distance)
{
	m_feet += distance.m_feet;
	m_inches += distance.m_inches;

	while (m_inches >= 12.0)
	{
		m_inches -= 12;
		m_feet++;
	}
}
