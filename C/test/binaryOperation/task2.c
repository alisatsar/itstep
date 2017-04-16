/*Задание 2:
Написать функцию перевода строкового представления двоичного числа(например,
	«0001 0101») в целое десятичное(21) и функцию, которая производит обратное
	преобразование с использованием битовых полей.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct NumberFlags
{
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
};

union Number
{
	char number;
	struct NumberFlags numberFlags;
};

bool checkContentsBinaryNumbers(char* userNumber, int length);

void main()
{
	union Number f;
	char* userNumber = malloc(8);

	int length = 8;
	unsigned int number = 0;
	do
	{
		printf("Enter the number size of 8 bits in the binary representation: ");
		scanf("%s", userNumber);
		length = strlen(userNumber);
	} while (length != 8 || (checkContentsBinaryNumbers(userNumber, length) != true));

	f.numberFlags.b0 = userNumber[0];
	f.numberFlags.b1 = userNumber[1];
}

bool checkContentsBinaryNumbers(char* userNumber, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (userNumber[i] != '0' && userNumber[i] != '1')
		{
			printf("The number must contain only 0 or 1\n");
			return false;
		}
		if (i == 7)
		{
			if (userNumber[i] == '0' || userNumber[i] == '1')
			{
				return true;
			}
		}
	}
}
