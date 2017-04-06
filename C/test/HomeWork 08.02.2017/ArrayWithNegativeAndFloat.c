/*Задание 1:
В одномерном массиве, состоящем из N вещественных чисел вычислить :
• Сумму отрицательных элементов
• Произведение элементов, находящихся между min и max элементами
• Произведение элементов с четными номерами
• Сумму элементов, находящихся между первым и последним отрицательными
элементами*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void fillArray(float array[], int count);
void printArray(float array[], int count);
int findSumMinus(float array[], int count);
int findSumWithoutMinMax(float array[], int count);
itn findSumMinusWithoutMinMax(float array[], int count);

int main()
{
	srand(time(0));

	float array[COUNT_ARRAY];

	printf("Random floating-point number from -10 to 10\n");
	fillArray(array, ARRAY_SIZE);
	
	printArray(array, ARRAY_SIZE);

	int sum = findSumMinus(array, ARRAY_SIZE);
	printf("The sum of negative values of the array = %.4f\n", sum);
	sum = findSumWithoutMinMax(array, ARRAY_SIZE);
	printf("The sum numbers of array without min and max values = %.4f\n", sum);
	findMultipleEvenNumbers(array, ARRAY_SIZE);
	findSumMinusWithoutMinMax(array, ARRAY_SIZE);
}

void fillArray(float array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		array[i] = (rand() % 10 / 1.1 * (-1)) + (rand() % 10);
		printf("%.4f\n", array[i]);
	}
}

void printArray(float array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%.4f\n", array[i]);
	}
}

void findSumMinus(float array[], int count)
{
	float sum = 0;
	for (int i = 0; i < count; i++)
	{
		if (array[i] < 0)
		{
			sum = sum + array[i];
		}
	}
	return sum;
}

void findSumWithoutMinMax(float array[], int count)
{
	float min;
	float max;
	float sum = 0;

	for (int i = 0; i < count; i++)
	{
		if (i == 0)
		{
			min = array[i];
			max = array[i];
		}
		if (min < array[i])
		{
			min = array[i];
		}
		if (max > array[i])
		{
			max = array[i];
		}
		sum = sum + array[i];
	}
	return sum - min - max;
}

int findMultipleEvenNumbers(float array[], int count)
{
	long float multiple = 1;
	for (int i = 0; i < count; i++)
	{
		if (i % 2)
		{
			multiple = multiple * array[i];
		}
	}
	printf("The multiple of the elements with even numbers = %.4lf\n", multiple);
}

int findSumMinusWithoutMinMax(float array[], int count)
{
	float minMinus;
	float maxMinus;
	float sum = 0;
		
	for (int i = 0; i < count; i++)
	{
		if (array[i] < 0)
		{
			minMinus = array[i];
			maxMinus = array[i];
		}
	}

	for (int i = 0; i < count; i++)
	{
		if (array[i] < 0)
		{
			if (minMinus > array[i])
			{
				minMinus = array[i];
			}
			if (maxMinus < array[i])
			{
				maxMinus = array[i];
			}
			sum = sum + array[i];
		}
	}
	printf("The sum negative numbers of array without min and max values = %.4f\n", sum - minMinus - maxMinus);
}
