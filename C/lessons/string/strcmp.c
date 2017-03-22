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
