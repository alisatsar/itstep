#include <iostream>
#include "distance.h"
#include <cstring>

Distance::Distance():m_feet(0), m_inches(0), m_MTF(3.280833F)
{
}

Distance::Distance(float meters): m_MTF(3.280833F)  //конструктором преобразования
{
	float feets = m_MTF * meters;
	m_feet = int(feets);
	m_inches = 12 * (feets - m_feet);
}

Distance::Distance(int feet, float inches): m_feet(feet), m_inches(inches), m_MTF(3.280833F)
{
}

void Distance::getDistance()
{
	std::cout << "Enter feets: ";
	std::cin >> m_feet;
	std::cout << "Enter inches: ";
	std::cin >> m_inches;
}

void Distance::showDistance() const
{
	std::cout << m_feet;
	std::cout << m_inches;;
}

Distance::operator float() const
{
	float fracfeet = m_inches / 12;
	fracfeet += static_cast<float>(m_feet);
	return fracfeet / m_MTF;
}

std::ostream& operator << (std::ostream& stream, Distance const& distance)
{
	stream << "feets: " << distance.m_feet << std::endl <<
		"inches: " << distance.m_inches << std::endl;

	return stream;
}
