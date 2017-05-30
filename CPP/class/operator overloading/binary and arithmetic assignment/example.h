#pragma once

class Distance
{
private:
	int m_feet;
	float m_inches;

public:
	Distance();
	Distance(int feet, float inches);
	void GetList();
	void ShowList();
	bool operator < (Distance distance) const;
	bool operator == (Distance distance) const;
	void operator += (Distance const& distance);
};
