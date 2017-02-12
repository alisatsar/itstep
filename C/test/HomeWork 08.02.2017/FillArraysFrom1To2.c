/*Задание 2:
Написать программу, копирующую последовательно элементы одного массива размером
10 элементов в 2 массива размером 5 элементов каждый.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 10

void fillArray(int arrayFull[]);

int main()
{
	int arrayFull[ELEMENTS];

	fillArrays(arrayFull);
}

void fillArray(int arrayFull[])
{
	int arraySecond[5];
	int arrayFirst[5];

	srand(time(0));
	for (int i = 0; i < ELEMENTS; i++)
	{
		arrayFull[i] = rand() % 10;
		printf("arrayFull[%i] = %i\n", i, arrayFull[i]);
	}

	for (int i = 0; i < ELEMENTS / 2; i++)
	{
		arrayFirst[i] = arrayFull[i];
		printf("arrayFirst[%i] = %i\n", i, arrayFirst[i]);
	}

	for (int i = 0; i < ELEMENTS / 2; i++)
	{
		arraySecond[i] = arrayFull[i + 5];
		printf("arraySecond[%i] = %i\n", i, arraySecond[i]);
	}
}