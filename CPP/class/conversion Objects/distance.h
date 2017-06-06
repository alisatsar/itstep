#pragma once
#include <iosfwd>

class Distance
{
private:
	const float m_MTF;
	int m_feet;
	float m_inches;

public:
	Distance();
	
	/////////////////////////////////////////////
	Distance(float meters); //конструктором преобразования
	/////////////////////////////////////////////
	
	Distance(int feet, float inches);
	void getDistance();
	void showDistance() const;
	
	
	/////////////////////////////////////////////
	operator float() const;
	/////////////////////////////////////////////
	
	
	friend std::ostream& operator << (std::ostream& stream, Distance const& distance);
};

std::ostream& operator << (std::ostream& stream, Distance const& distance);
