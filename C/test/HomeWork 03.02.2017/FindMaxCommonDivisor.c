/*Задание 1
Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых
чисел*/

#include <stdio.h>

int findMaxCommonDivisor(int a, int b);

int main()

{
	int a;
	int b;

	printf("Enter number a from 1 to 100:\n");
	scanf("%i", &a);

	printf("Enter number b from 1 to 100:\n");
	scanf("%i", &b);

	printf("Maximum common divisor numbers %i and %i = %i\n", a, b, findMaxCommonDivisor(a, b));
}

int findMaxCommonDivisor(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return findMaxCommonDivisor(b, a % b);
	}
}