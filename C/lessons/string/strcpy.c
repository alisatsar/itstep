#define SIZE 40
#define LIM 5

char* s_gets(char* st, int n);

int main()
{
	char list[LIM][SIZE];
	char temp[SIZE];
	int i = 0;
	
	printf("Enter %i words, that starter with letter q:\n", LIM);

	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != 'q')
		{
			printf("%s not started with letter \"q\"", temp);
		}
		else
		{
			strcpy(list[i], temp);    //копирование из строки temp в строку list[i]
			i++;
		}
	}
	puts("The list of word, what has been taken:");
	for (int i = 0; i < LIM; i++)
	{
		puts(list[i]);
	}
}

char* s_gets(char* st, int n)
{
	char* retVal;
	int i = 0;

	retVal = fgets(st, n, stdin);

	if (retVal)
	{
		while (st[i] != '\n' && st[i] != '\0')
		{
			i++;
		}
		if (st[i] == '\n')
		{
			st[i] = 0;
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return retVal;
}

#include <stdio.h>
#include <string.h>

#define SIZE 40
#define WORDS "worst"

int main()
{
	const char* orig = WORDS;
	char copy[SIZE] = "Just you are best";

	char* ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy + 13, orig);
	puts(copy);
	puts(ps);
}

