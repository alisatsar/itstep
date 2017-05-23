#include "geometry.h"
#include <iostream>

int main()
{
	Rectangle r;

	r.Init(0, 0, 100, 40);

	Point p;
	p.Init(60, 20);

	if (r.Contains(p))
	{
		std::cout << "r contains p\n";
	}
	else
	{
		std::cout << "r doesn't contin p\n";
	}

	Size size;
	size.Init(100, 50);

	Rectangle r1;

	r1.Init(p, size);

	Rectangle r2 = r.IntersectWith(r1);
	r2.Print();

	return 0;
}
