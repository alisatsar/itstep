#include <stdio.h>
#include <string.h>

#define SIZE 40
#define TR 7
#define LIM 5

char* s_gets(char* st, int n);

int main()
{
	char qwords[LIM][TR];
	char temp[SIZE];
	int i = 0;

	printf("Enter %i words, that started with letter k:", LIM);

	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != 'k')
		{
			printf("This words not started with k\n");
		}
		else
		{
			strncpy(qwords[i], temp, TR - 1);   //копирует строку temp в qwords со строгим ограничением TR- 1. 
      //если TR исчерпан до достижения конца исходной строки, то нулевой символ не добавляется. /0 нужно задавать жестко
			qwords[i][TR - 1] = '\0';
			i++;
		}
	}
	for (int i = 0; i < LIM; i++)
	{
		puts(qwords[i]);
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
