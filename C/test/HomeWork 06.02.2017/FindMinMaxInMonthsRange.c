/*Задание 2: Пользователь вводит прибыль фирмы за год(12 месяцев).Затем пользователь
вводит диапазон(например, 3 и 6 – поиск между 3 - м и 6 - м месяцем).Необходимо
определить месяц, в котором прибыль была максимальна и месяц, в котором прибыль
была минимальна с учетом выбранного диапазона.*/

#include <stdio.h>

#define COUNT_MONTH 12

void enterArray(int profitInMonths[], int count);
void findMinAndMaxProfit(int profitInMonths[]);

int main()
{
	int profitInMonths[COUNT_MONTH];

	enterArray(profitInMonths, COUNT_MONTH);

	findMinAndMaxProfit(profitInMonths);
}

void enterArray(int profitInMonths[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("Please, enter your profit in month %i: ", i + 1);
		scanf("%i", &profitInMonths[i]);
	}
}

void findMinAndMaxProfit(int profitInMonths[])
{
	int monthStart;
	int monthFinish;
	int min = 0;
	int max = 0;
	int minMonth;
	int maxMonth;

	printf("Please, enter month, with which you want to start define maximum and minimum your profit: ");
	scanf("%i", &monthStart);

	printf("Please, enter month, with which you want to finish define maximum and minimum your profit: ");
	scanf("%i", &monthFinish);

	if (monthFinish < monthStart)
	{
		int a = monthFinish;
		monthFinish = monthStart;
		monthStart = a;
	}
	
	for (int i = monthStart - 1; i < monthFinish; i++)
	{

		if (i == monthStart - 1)
		{
			min = profitInMonths[i];
			max = profitInMonths[i];
		}
		if (min > profitInMonths[i])
		{
			min = profitInMonths[i];
			minMonth = i + 1;
		}
		if (max < profitInMonths[i])
		{
			max = profitInMonths[i];
			maxMonth = i + 1;
		}
	}
	printf("Your min profit was %i in month %i\n", min, minMonth);
	printf("Your max profit was %i in month %i\n", max, maxMonth);
}