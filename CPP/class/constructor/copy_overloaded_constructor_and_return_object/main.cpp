#include <iostream>
#include "count.h"

int main()
{
	//перегруженный конструктор

	/*Distance distance1;
	Distance distance2(1, 3.4);
	Distance distanceFirstAndSecond;

	distance1.GetDistance();
	distanceFirstAndSecond.AddDistance(distance1, distance2);

	std::cout << "\ndistance First: ";
	distance1.ShowDistance();
	std::cout << "\ndistance Second: ";
	distance2.ShowDistance();
	std::cout << "\ndistance First and Second: ";
	distanceFirstAndSecond.ShowDistance();*/


	//копирующий конструктор
	Distance distance1(3, 4.5);
	Distance distance2(distance1);
	Distance distance3 = distance1;

	//Объекты возвращаемые функцией
	Distance distance4 = distance1.MultipleDistance(distance2);

	return 0;
}
