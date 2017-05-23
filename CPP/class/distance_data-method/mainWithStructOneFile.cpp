#include <iostream>

struct Point
{
	int x;
	int y;

void Set(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Print()
{
	std::cout << x << "\n" << y << std::endl;
}
};

int main()
{
	Point d1;

	d1.Set(5, 61);
	d1.Print();

	d1.Set(3, 64);
	d1.Print();

	return 0;
}
