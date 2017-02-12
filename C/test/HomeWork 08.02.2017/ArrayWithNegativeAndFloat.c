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

#define COUNT_ARRAY 10

void fillArray(float array[], int count);
void findSumMinus(float array[], int count);
void findSumWithoutMinMax(float array[], int count);
void findSumMinusWithoutMinMax(float array[], int count);

int main()
{
	srand(time(0));

	float array[COUNT_ARRAY];

	fillArray(array, COUNT_ARRAY);

	findSumMinus(array, COUNT_ARRAY);

	findSumWithoutMinMax(array, COUNT_ARRAY);

	findMultipleEvenNumbers(array, COUNT_ARRAY);

	findSumMinusWithoutMinMax(array, COUNT_ARRAY);
}

void fillArray(float array[], int count)
{
	printf("Random floating-point number from -10 to 10\n");
	for (int i = 0; i < count; i++)
	{
		array[i] = (rand() % 10 / 1.1 * (-1)) + (rand() % 10);
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
	printf("The sum of negative values of the array = %.4f\n", sum);
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
	printf("The sum numbers of array without min and max values = %.4f\n", sum - min - max);
}

void findMultipleEvenNumbers(float array[], int count)
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

void findSumMinusWithoutMinMax(float array[], int count)
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