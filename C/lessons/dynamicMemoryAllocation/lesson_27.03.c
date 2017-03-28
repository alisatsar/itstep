/*#include <stdio.h>
#include <string.h>

enum Type
{
	Int = 1,
	Float = 2,
	Double = 3,
	Char = 4,
	Pointer = 5
};

union Data
{
	int valueInt;
	float valueFloat;
	double valueDouble;
	char valueStr[50];
	char* pointer;
};

struct DataItem
{
	enum Type type;
	union Data data;
};

int main()
{
	struct DataItem userValue[5];

	for (int i = 0; i < 5; i++)
	{
		printf("Enter type of varible: \n");
		printf("Int = 1\nFloat = 2\nDouble = 3\nChar = 4\nPointer = 5\n");
		scanf("%i", &userValue[i].type);

		int a;
		do
		{
			a = getchar();
		} while (a != '\n' && a != EOF);
		printf("Enter value\n");
		if (userValue[i].type == 4 || userValue[i].type == 5)
		{
			char buffer[50];
			fgets(buffer, 50, stdin);
			strcpy(&userValue[i].data, buffer);
		}
		else
		{
			scanf("%i", &userValue[i].data);
		}
	}
}*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

/*int main()
{
	int counter = 0;
	while (true)
	{
		int * mem = malloc(100 * 1024 * 1024);
		if (mem == NULL)
		{
			break;
		}
		counter++;
		Sleep(1000);
	} 
		
	printf("%i", counter * 100);
	getchar();
}*/

/*int main()
{
	int counter = 0;

	int* pointer[100];
	while (true)
	{
		pointer[counter] = malloc(100 * 1024 * 1024);
		if (pointer[counter] == NULL)
		{
			break;
		}
		counter++;
		Sleep(1000);
	}

	printf("%i", counter * 100);
	getchar();

	for (int i = 0; i < counter; i++)
	{
		free(pointer[i]);
	}

	
}*/

int main()
{
	char** book = malloc(3 * sizeof(char*));

	for (int i = 0; i < 3; i++)
	{
		book[i] = malloc(2000 * sizeof(char));
		//*(book + i) = malloc(2000 * sizeof(char));
	}

	for (int i = 0; i < 3; i++)
	{
		printf("book %i: \n", i + 1);
		scanf("%s", *(book + i));
		printf("\n");
	}

	for (int i = 0; i < 3; i++)
	{
		printf("print book %i: \n", i + 1);
		printf("%s", *(book + i));
	}
	
	for (int i = 2; i >= 0; i--)
	{
		free(*(book + i));
	}

	free(book);

}
