#include <stdio.h>
#include <string.h>

#define SIZE 6

int main()
{
	char const* list[SIZE] = { "astronomy", "astra", "astronaft", "os", "astma", "as" };
	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (strncmp(list[i], "astro", 5) == 0) //Функция strncmp() сравнивает строки до тех пор,
    //пока не обнаружит в них различия либо пока не сравнит количество символов в обеих строках, указанное в третьем аргументе
		{
			printf("Has define: %s\n", list[i]);
			count++;
		}
	}
	printf("Quantity words in list, " "that started with \"astro\": %i\n", count);
}
