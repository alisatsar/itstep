#include "Distance.h"

#include <iostream>

Distance::Distance()
{
	m_feet = 0;
	m_inches = 0;
}

//имя класса :: имя метода
Distance::Distance(int feet, float inches)
{
	m_feet = feet;
	m_inches = inches;
}

Distance::Distance(int feet)
{
	m_feet = feet;
	m_inches = 0;
}

int Distance::GetFeet() const
{
	return m_feet;
}

float Distance::GetInches() const
{
	return m_inches;
}

void Distance::SetData(int feet, float inches)
{
	m_feet = feet;
	m_inches = inches;
}

void Distance::Read()
{
	std::cin >> m_feet >> m_inches;
}

void Distance::Print()
{
	std::cout << m_feet << "\'" << m_inches << "\"" << std::endl;
}

Distance Distance::operator+(Distance const& rhs)
{
	Distance result(*this);
	result += rhs;
	return result;
}

Distance Distance::operator-(Distance const& rhs)
{
	Distance result(*this);
	result -= rhs;
	return result;
}

void Distance::operator+=(Distance const& rhs)
{
	m_feet += rhs.m_feet;
	m_inches += rhs.m_inches;
	if (m_inches >= 12.0f)
	{
		m_inches -= 12.0f;
		m_feet += 1;
	}
}

void Distance::operator-=(Distance const& rhs)
{
	m_feet -= rhs.m_feet;
	m_inches -= rhs.m_inches;
	if (m_inches < 0)
	{
		m_inches += 12.0f;
		m_feet -= 1;
	}
}

Distance& Distance::operator++()
{
	m_feet++;
	return *this;
}

Distance Distance::operator++(int)
{
	Distance result(*this);
	m_feet++;
	return result;
}

float operator/(Distance const& d1, Distance const& d2)
{
	float inches1 = d1.GetFeet()*12.0f + d1.GetFeet();
	float inches2 = d2.GetFeet()*12.0f + d2.GetFeet();
	return inches1 / inches2;
