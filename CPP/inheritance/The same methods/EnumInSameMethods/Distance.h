#pragma once
#include <iostream>
enum posneg { pos = 0, neg = 1 };

class Distance
{
protected:
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0.0)
	{
	}

	Distance(int ft, float inc) : feet(ft), inches(inc)
	{
	}

	void GetDistance()
	{
		std::cout << "Enter feet: ";
		std::cin >> feet;
		std::cout << "Enter inches: ";
		std::cin >> inches;
	}

	void ShowDistance() const
	{
		std::cout << feet << "\'-" << inches << '\""';
	}
};

class DistanceSign : public Distance
{
private:
	posneg sign;
public:
	DistanceSign() : Distance()
	{
		sign = pos;
	}

	DistanceSign(int ft, float in, posneg sg = pos) : Distance(ft, in)
	{
		sign = sg;
	}

	void GetDistance()
	{
		Distance::GetDistance();
		char ch;
		std::cout << "Enter character (+ or -): ";
		std::cin >> ch;
		sign = (ch == '+') ? pos : neg;
	}
	void ShowDistance() const
	{
		std::cout << ((sign == pos) ? "+" : "-");
		Distance::ShowDistance();
	}
};
