/*#include <stdio.h>

#define STLEN 81

int main()
{
	char words[STLEN];
	puts("Enter string\n");
	gets(words);
	printf("Your string\n");
	printf("%s\n", words);
	puts(words);
}*/

/*#include <stdio.h>

#define STLEN 5

int main()
{
	char words[STLEN];
	
	puts("Enter string");
	fgets(words, STLEN, stdin);
	puts(words);
	fputs(words, stdout);

	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
	{
		fputs(words, stdout);
	}
}*/

#include <stdio.h>
#define STLEN 10

int main()
{
	char words[STLEN];
	int i;
	puts("ENter string (or empty string for exit from programm): ");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
	{
		i = 0;
		while (words[i] != '\n'&& words[i] != '\0')
		{
			i++;
		}
		if (words[i] == '\n')
		{
			words[i] = 0;
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
		puts(words);
	}
}
