/*Задание 2:
Написать программу, копирующую последовательно элементы одного массива размером
10 элементов в 2 массива размером 5 элементов каждый.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 10

void fillArrays(int arrayFull[]);

int main()
{
	int arrayFull[ELEMENTS];
	int arrayFirst[ELEMENTS / 2];
	int arraySecond[ELEMENTS / 2];

	fillArrays(arrayFull, arrayFirst, arraySecond);
	printArray(arrayFull, ELEMENTS);
	printArray(arrayFirst, ELEMENTS / 2);
	printArray(arraySecond, ELEMENTS / 2);
}

void fillArrays(int arrayFull[], int arrayFirst[], int arraySecond[])
{
	srand(time(0));
	for (int i = 0; i < ELEMENTS; i++)
	{
		arrayFull[i] = rand() % 10;
	}

	for (int i = 0; i < ELEMENTS / 2; i++)
	{
		arrayFirst[i] = arrayFull[i];
	}

	for (int i = 0; i < ELEMENTS / 2; i++)
	{
		arraySecond[i] = arrayFull[i + 5];
	}
}
