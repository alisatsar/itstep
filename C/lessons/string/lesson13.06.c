#include <stdio.h>

/*int lenght(char* str);
void modifyLetters(char* str, int letters);

enum letters
{
	App = 1,
	Down = 2
};

int main()
{
	char str[] = "heLLO world";

	printf("%s\n", str);

	enum letters letters;

	printf("What you want to modify your string: App = 1, Down = 2.\n");
	scanf("%i", &letters);
	
	int len = lenght(str);

	modifyLetters(str, letters);
	printf("%s\n", str);
}

int lenght(char* str)
{
	int count = 0;
	do{
		count++;
	}while (str[count] != 0);
	
	return count - 1;
}

void modifyLetters(char* str, enum letters letters)
{
	int i = 0;
	char ch;
	switch (letters)
	{
	case App:
		do{
			ch = *(str + i);
			if (ch > 'a' && ch < 'z')
			{
				*(str + i) = ch - 32;
			}
			i++;
		} while (ch != 0);
		break;
	case Down:
		do{
			ch = *(str + i);
			if (ch > 'A' && ch < 'Z')
			{
				*(str + i) = ch + 32;
			}
			i++;
		} while (ch != 0);
		break;
	}
}*/

/*#define SIZE_STRING 1024

void sayHello(char const* greatingStart, char const* greatingEnd, char const* name, char* result);
void myStrCat(char const* array, char* result);

int main()
{
	char greatingStart[] = "Hello, ";
	char greatingEnd[] = "! Nice to meet you.";
	char result[SIZE_STRING] = "";
	
	char name[10];
	
	fgets(name, 10, stdin);

	sayHello(greatingStart, greatingEnd, name, result);

	printf("%s\n", result);
}

void sayHello(char const* greatingStart, char const* greatingEnd, char const* name, char* result)
{
	myStrCat(greatingStart, result);
	myStrCat(name, result);
	myStrCat(greatingEnd, result);
}

void myStrCat(char const* array, char* result)
{
	while (*result != 0)
	{
		result++;
	}
	while (*array != 0 && *array != '\n')
	{
		*result = *array;
		result++;
		array++;
	}
}*/
