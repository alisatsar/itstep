#include "ArrayUtils.h"
#include <iostream>
#include <string.h>

struct Point
{
	int x;
	int y;
};

int main()
{
	int* pA = new int[10];

	for (int i = 0; i < 10; i++)
	{
		pA[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << pA[i] << " ";
	}

	delete[]pA;

	char* str = new char[20];
	strcpy(str, "Welcome");
	std::cout << str;
	delete[]str;

	return 0;
}



//int a = 100;
//int& refo = a;
//
//std::cout << a << " " << refo << "\n";
//
//Point p = { 3, 5 };
//Point& refp = p;
//
//Point* pP = &p;
//
//pP->x = 4;
//
//refp.x = 6;
//
//const int& c = 0;
//
//int* pA = new int;		//динамическое выделение
//delete pA;
//
//char* pC = new char[10];  //количество элементов
//delete[]pC;
