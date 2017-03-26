#include <stdio.h>
#include <string.h>

#define TITLE_SIZE 40
#define AUTHOR_SIZE 40
#define BOOK_SIZE 100

char* s_gets(char* st, int n);

struct book
{
	char title[TITLE_SIZE];
	char author[AUTHOR_SIZE];
	float value;
};

int main()
{
	struct book library[BOOK_SIZE];
	int count = 0;
	
	printf("Enter the name of book: ");
	while (count < BOOK_SIZE && s_gets(library[count].title, TITLE_SIZE) != NULL
		&& library[count].title[0] != 0)
	{
		printf("Enter author: \n");
		s_gets(library[count].author, AUTHOR_SIZE);
		printf("Enter price: \n");
		scanf("%i", &library[count].value);
		while (getchar() != '\n')
		{
			continue;
		}
		if (count < BOOK_SIZE)
		{
			printf("Enter name of another book\n");
		}
		count = count + 1;
	}
	if (count > 0)
	{
		printf("Your library\n");
		for (int i = 0; i < count; i++)
		{
			printf("%s author %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
		}
	}
	else
	{
		printf("You don't have book! It's very bad!\n");
	}
}

char* s_gets(char* st, int n)
{
	char* result;
	char* find;
	
	result = fgets(st, n, stdin);

	if (result)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return result;
}
