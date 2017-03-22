#include <stdio.h>
#include <string.h>

#define SIZE 80

char* s_gets(char* st, int n);

int main()
{
	char flower[SIZE];
	char addon[] = " smell like old shoes";

	puts("What is your favorite flower?");
	if (s_gets(flower, SIZE))
	{
		strcat(flower, addon);
		puts(flower);
		puts(addon);
	}
	else
	{
		puts("This is end of file");
	}
	puts("The poggramm is complete");
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
