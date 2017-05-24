#pragma once

class Distance
{
private:
	int m_feet;
	float m_inches;
	
public:
	Distance();
	Distance(int feet, int inches);
	void GetDistance();
	void ShowDistance();
	void AddDistance(Distance, Distance);
	Distance MultipleDistance(Distance);
};
