#include <iostream>

#include <string>

class Distance
{
private:
	int feet;
	float inches;

public:
	class InchesEx
	{
	public: 
		std::string origin;
		float iValue;

		InchesEx(std::string or, float in)
		{
			origin = or;
			iValue = in;
		}
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
			throw InchesEx("Constructor with 2 arguments", inc);
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
			throw InchesEx("The function of GetDist()", inches);
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
		Distance d1(17, 13.5);
		Distance d2;

		d2.GetDist();

		std::cout << "\nDistance 1 = ";
		d1.ShowDistance();

		std::cout << "\nDistance 2 = ";
		d2.ShowDistance();
	}
	catch (Distance::InchesEx ex)
	{
		std::cout << "\nError!" << ex.origin << "\nand wrong value: " << ex.iValue << std::endl;
	}
}
