#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* file = fopen("D:\\book.book", "r");

	//fseek(file, 50, SEEK_SET);

	char* buff = malloc(50);
	char* a;

	while (fgets(buff, 50, file))
	{
		a = strchr(buff, '\n');
		if (a == NULL)
		{
			printf("%s", buff);
		}
		else
		{
			*a = '\0';
			printf("%s", buff);
			break;
		}
	}

	fclose(file);
}
