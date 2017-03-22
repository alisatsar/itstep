/*struct Book
{
	char name[2];
	char author[50];
}:


struct book book;

book.name
book.author

strcpy(book.name, "abc"); //записать в name значение


struct Book books[10]

	books[1].author*/

/*#include <stdio.h>

struct Book
{
	char name[40];
	char author[30];
	char gente[30];
	int year;
};

void getsBooks(struct Book* books);
void printBooks(struct Book* books);

int main()
{
	struct Book books[2];
	
	struct Book book2 = { "book2", 2932 };
	struct Book book3 = { .name = "book2", .year = 2932 };
	getsBooks(&books);
	printBooks(&books);
	
}

void getsBooks(struct Book* books)
{
	for (int i = 0; i < 2; i++)
	{
		printf("Enter name: ");
		fgets(books[i].name, 40, stdin);
		printf("Enter author: ");
		fgets(books[i].author, 30, stdin);
		printf("Enter gente: ");
		fgets(books[i].gente, 30, stdin);
		printf("Enter year: ");
		scanf("%i", &books[i].year);
		char ch;
		do{
			ch = getchar();
		} while (ch != '\n' & ch != EOF);
	}
}

void printBooks(struct Book* books)
{
	for (int i = 0; i < 2; i++)
	{
		printf("name %s", books[i].name);
		printf("author %s", books[i].author);
		printf("gente %s", books[i].gente);
		printf("year %i\n", books[i].year);
	}
}*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BOOK_COUNT 3
#define NAME_LENGTH 50
#define AUTHOR_LENGTH 30

struct Book
{
	char Author[AUTHOR_LENGTH];
	char Name[NAME_LENGTH];
	int Year;
};

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void printLibrary(struct Book books[BOOK_COUNT],
	int count)
{
	for (int i = 0; i < BOOK_COUNT; i++)
	{
		printf("---\nBook name: %s\n", books[i].Name);
		printf("Author: %s\n", books[i].Author);
		printf("Year: %i\n", books[i].Year);
	}
}

int bookCompare(struct Book* book1,
struct Book* book2)
{
	//(*book1).name то же самое book1->name
	return strcmp((*book1).Name, (*book2).Name);
}

void sortLibrary(struct Book books[BOOK_COUNT],
	int count)
{
	for (size_t i = 0; i < BOOK_COUNT - 1; i++)
	{
		for (size_t j = 0; j < BOOK_COUNT - i - 1; j++)
		{
			if (bookCompare(&books[j], &books[j + 1]))
			{
				struct Book tmp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	struct Book books[BOOK_COUNT] =
	{
		{
			.Name = "Book3",
			.Author = "Author3",
			.Year = 2013
		},
		{
			.Name = "Book2",
			.Author = "Author2",
			.Year = 2017
		},
		{
			.Name = "Book1",
			.Author = "Author1",
			.Year = 2016
		}
	};

	printLibrary(books, BOOK_COUNT);
	sortLibrary(books, BOOK_COUNT);
	printf("===== After sorting ======");
	printLibrary(books, BOOK_COUNT);
}
