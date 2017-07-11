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


////////////////////////////////////////////////////////////////////////////////////////////////////

class P
{
public:
	P(int a, int b)
	{
	}

	explicit P(int a, int b, int c)
	{
	}
};

int main()
{
	P x(77, 5); //ok
	P y{ 11, 5 }; //ok

	P z{ 22, 44, 55 }; //ok
	P v = { 77, 66 };//ok неявное преобразование типа допускается
	P w = { 77, 77, 55 }; //error (неявное преобразование типа)
}
	
