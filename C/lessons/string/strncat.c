#include <stdio.h>
#include <string.h>

#define SIZE 30
#define BUGSIZE 13

char* s_gets(char* st, int n);

int main()
{
	char flower[SIZE];
	char addon[] = " smell like old shoes";
	char bug[BUGSIZE];
	int available;

	puts("What is your favorite flower?");
	s_gets(flower, SIZE);
	if ((strlen(addon) + strlen(flower)+ 1) <= SIZE)
	{
		strcat(flower, addon);
	}
	puts(flower);
	puts("What is your favorite insect");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
  //останавливается после available доп. символов
	strncat(bug, addon, available);
	puts(bug);
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
