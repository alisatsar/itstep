/*Задание 2:
Написать программу, которая хранит информацию об автомобиле(марка, модель, цвет
(enum), тип топлива(enum) и год) в динамическом массиве.Пользователь определяет
размерность массива и вводит 5 автомобилей.Реализовать возможность поиска всех
автомобилей младше определенного года.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_ARRAY 5

enum Color
{
	Red = 1,
	Green = 2,
	Black = 3,
	While = 4,
	Grey = 5
};

enum FuelType
{
	Benzine80 = 1,
	Benzine92 = 2,
	Benzine95 = 3,
	Gas = 4,
	Diesel = 5
};

struct Car
{
	char Brand[30];
	char Model[30];
	enum Color color;
	enum FuelType fuelType;
	int Year;
};

char* sgets(char * st, int n);
void cleanInput();

int main()
{
	int structSize  = 0;

	while (structSize < sizeof(struct Car))
	{
		printf("Enter the size of memory for array, not less %i byte: ", sizeof(struct Car) * SIZE_ARRAY);
		scanf("%i", &structSize);
	}
	cleanInput();

	struct Car* car[SIZE_ARRAY];

	int i = 0;

	while (i < SIZE_ARRAY)
	{
		car[i] = malloc(structSize);
		sgets(car[i]->Brand, 30);
	}

}

char* sgets(char* st, int n)
{
	char* result;
	char* find;

	result = fgets(st, n, stdin);
	if (result)
	{
		find = strcht(st, '\n');
		if (find)
		{
			*find = 0;
		}
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return result;
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}
