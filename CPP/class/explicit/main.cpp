#include "Distance.h"
#include <iostream>

void fancyDist(Distance);

int main()
{
	Distance  dist1(2.35F);  // конструктор с 1 аргументом      
							 // преобразовывает метры в Расстояние  
							 // Distance dist1 = 2.35F;   
							 // ОШИБКА, если ctor является явным(EXPLICIT)   
	cout << "\ndist1 = "; 
	dist1.showdist(); 

	float mtrs = 3.0F;   
	cout << "\nDist1 ";

	////////////////////
	fancyDist(mtrs);  // ОШИБКА, если ctor является явным(EXPLICIT) 
	//////////////////////

	return 0;
}

void fancyDist(Distance d) 
{ 
	cout << "(в футах и дюймах) = ";   
	d.showdist();   
	cout << endl; 
}
