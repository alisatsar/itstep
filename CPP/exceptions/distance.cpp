#include <iostream>

class Distance
{
private:
	int feet;
	float inches;

public:
	class InchesEx
	{
	};

	Distance()
	{
		feet = 0;
		inches = 0.0;
	}

	Distance(int ft, float inc)
	{
		if (inc >= 12.0)
		{
			throw InchesEx();
		}
		feet = ft;
		inches = inc;
	}

	void GetDist()
	{
		std::cout << "\nEnter feet: ";
		std::cin >> feet;
		std::cout << "\nEnter inches: ";
		std::cin >> inches;

		if (inches >= 12.0)
		{
			throw InchesEx();
		}
	}

	void ShowDistance()
	{
		std::cout << feet << "\'" << inches << '\"';
	}
};

int main()
{
	try
	{
		Distance d1(17, 3.5);
		Distance d2;

		d2.GetDist();

		std::cout << "\nDistance 1 = ";
		d1.ShowDistance();

		std::cout << "\nDistance 2 = ";
		d2.ShowDistance();
	}
	catch (Distance::InchesEx)
	{
		std::cout << "\nError!";
	}
}
