//Написать функцию, которая удаляет из строки символ с заданным номером

#include <stdio.h>

#define SIZESTRING 50

int length(char* str);
void deliteChar(char* str, int* len);

int main()
{
	char str[SIZESTRING];
	printf("Enter your text\n");
	fgets(str, SIZESTRING, stdin);
	int len = length(str);

	deliteChar(str, &len);
}

int length(char* str)
{
	int count = 0;
	do {
		count++;
	} while (str[count] != 0);

	return count - 1;
}

void deliteChar(char* str, int* len)
{
	int userDeleteChar;
	printf("the text contains %i character. Enter the number of character, that you want delete\n", *len);
	scanf("%i", &userDeleteChar);

	for (int i = userDeleteChar - 1; i < *len; i++)
	{
		str[i] = str[i + 1];
	}
	puts(str);
}
