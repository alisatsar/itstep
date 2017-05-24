#include "count.h"
#include <iostream>

Distance::Distance() : m_feet(0), m_inches(0.0f)
{
	std::cout << "Construction\n";
}
	
Distance::Distance(int feet, int inches) : m_feet(feet), m_inches(inches)
{
	std::cout << "Construction\n";
}

void Distance::GetDistance()
{
	std::cout << "\nEnter the nubmer of feet ";
	std::cin >> m_feet;
	std::cout << "\nEnter the number of inches ";
	std::cin >> m_inches;
}

void Distance::ShowDistance()
{
	std::cout << m_feet << "\'-" << m_inches << '\"';
}

void Distance::AddDistance(Distance distanceFirst, Distance distanceSecond)
{
	m_inches = distanceFirst.m_inches + distanceSecond.m_inches;
	m_feet = 0;
	if (m_inches >= 12.0)
	{
		m_inches = m_inches - 12.0;
		m_feet++;
	}
	m_feet += distanceFirst.m_feet + distanceSecond.m_feet;
}

Distance Distance::MultipleDistance(Distance distance2)
{
	Distance buffer;

	buffer.m_inches = m_inches * distance2.m_inches;
	m_feet = 0;
	if (m_inches >= 12.0)
	{
		m_inches = m_inches - 12.0;
		m_feet++;
	}
	buffer.m_inches += m_feet * distance2.m_feet;

	return buffer;
}
