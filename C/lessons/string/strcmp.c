#include <stdio.h>

#define SIZE 40
#define ANSWER "House"

void s_gets(char* string, int size);

int main()
{
	char try[SIZE];
	puts("Who are your doctor?");

	s_gets(try, SIZE);
	
  //сравнивает две строки, надо следить за тем, чтобы в конце не стоял символ \n при вводе с fgets()
	while (strcmp(try, ANSWER))
	{
		puts("This is wrong answer. Please, try again");
		fgets(try, SIZE, stdin);
	}
	puts("This is right answer now");
}

void s_gets(char* string, int size)
{

	fgets(string, size, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = 0;
		}
		string++;
	}
}

#include <stdio.h>
#include <string.h>

int main()
{
	printf("strcmp(\"A\", \"A\") return "); 
	printf("%d\n", strcmp("A", "A")); 	//возвращает 0

	printf("strcmp(\"A\", \"B\") return ");
	printf("%d\n", strcmp("A", "B")); 	//возвращает -1

	printf("strcmp(\"B\", \"A\") return ");
	printf("%d\n", strcmp("B", "A"));	//возвращает 1

	printf("strcmp(\"C\", \"A\") return ");
	printf("%d\n", strcmp("C", "A"));	//возвращает 1

	printf("strcmp(\"Z\", \"a\") return ");
	printf("%d\n", strcmp("Z", "a"));	//возвращает -1

	printf("strcmp(\"apples\", \"apple\") return ");
	printf("%d\n", strcmp("apples", "apple"));	//возвращает 1
}
