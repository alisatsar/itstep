#include <stdio.h>
#include <string.h>

void copyFile(char* string1, char* string2);

int main()
{
	char* string1 = malloc(40);
	char* string2 = malloc(40);

	printf("Enter the way to file to reed:");
	scanf("%s", string1);
	printf("Enter the way to file to white:");
	scanf("%s", string2);

	copyFile(string1, string2);

	free(string1);
	free(string2);
}

void copyFile(char* string1, char* string2)
{
	FILE* file1 = fopen(string1, "r");
	FILE* file2 = fopen(string2, "w");

	if (file1 == NULL)
	{
		printf("error, failed to open file %s", string1);
		return 1;
	}
	if (file2 == NULL)
	{
		printf("error, failed to open file %s", string2);
		return 1;
	}

	char* buff = malloc(256);

	while (fgets(buff, 256, file1))
	{
		fputs(buff, file2);
		printf("%s", buff);
	}

	fclose(file1);
	fclose(file2);
}
