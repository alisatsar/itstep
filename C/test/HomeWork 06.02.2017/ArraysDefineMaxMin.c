/*Задание 1: В одномерном массиве, заполненном случайными числами, определить
минимальный и максимальный элементы.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define DAYS_COUNT 10

int main()
{
	int howMuchProductSold[DAYS_COUNT];
	int minProductsSold;
	int maxProductsSold;

	for (int i = 0; i < DAYS_COUNT; i++)
	{
		srand(time(0));
		howMuchProductSold[i] = rand() % 100;
		printf("How mush the products was sold for %i day: %i\n", i + 1, howMuchProductSold[i]);
		Sleep(1500);

		if (i == 0)
		{
			minProductsSold = howMuchProductSold[i];
			maxProductsSold = howMuchProductSold[i];
		}

		if (minProductsSold > howMuchProductSold[i])
		{
			minProductsSold = howMuchProductSold[i];
		}
		if (maxProductsSold < howMuchProductSold[i])
		{
			maxProductsSold = howMuchProductSold[i];
		}
	}

	printf("Maximum the products was sold: %i\n",
		maxProductsSold);
	printf("Minimum the products was sold: %i\n",
		minProductsSold);
}
