#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define TEXT_SIZE 256
#define NAME_SIZE 100
#define HEDDER_NAME "Recipe's name: "
#define HEDDER_TEXT "Recipe's text: "
#define HEDDER_RATING "Recipe's rating: "

enum Menu
{
	AddRecipe = 1,
	ViewRecipe,
	EditRecipe,
	DeleteRecipe,
	ExitFromProgram
};

struct Recipe
{
	char Name[NAME_SIZE];
	char Text[256];
	int Rating;
};

void addRecipe();
void cleanInput();
void convertRecipeNameinFileName(char* buff);
void viewAllRecipe(char* fileName);
void viewRecipe();
void editRecipe();
void deleteRecipe();

int main()
{
	enum Menu menu = 0;

	while (menu != 5)
	{
		do
		{
			printf("Please enter what you want to do:\n");
			printf("1 - Add recipe\n2 - View recipe\n3 - Edit recipe\n4 - Delete Recipe\n5 - Exit from program\n");
 			scanf("%i", &menu);
		} while (menu < 1 || menu > 5);
		
		switch (menu)
		{
		case AddRecipe:
			addRecipe();
			break;
		case ViewRecipe:
			viewRecipe();
			break;
		case EditRecipe:
			editRecipe();
			break;
		case DeleteRecipe:
			deleteRecipe();
			break;
		case ExitFromProgram:
			return 0;
			break;
		}
	}
}

void addRecipe()
{
	cleanInput();
	struct Recipe recipe;
	char buff[NAME_SIZE];
		
	printf("Enter the name of recipe: \n");
	memset(recipe.Name, 0, NAME_SIZE);
	fgets(recipe.Name, NAME_SIZE, stdin);
	memset(buff, 0, NAME_SIZE);
	strcpy(buff, recipe.Name);
	convertRecipeNameinFileName(buff);

	char fileName[NAME_SIZE] = "d:\\\\recipe\\\\";
	strcat(fileName, buff);
	strcat(fileName, ".bin");

	FILE* file = fopen(fileName, "wb");
	
	printf("Enter the text of recipe: ");
	memset(recipe.Text, 0, NAME_SIZE);
	fgets(recipe.Text, TEXT_SIZE, stdin);

	recipe.Rating = 0;
	while (recipe.Rating < 1 || recipe.Rating > 10)
	{
		printf("Enter the rating of recipe: ");
		scanf("%i", &recipe.Rating);
	}
	cleanInput();

	fseek(file, 0, SEEK_END);
	fwrite(&recipe, sizeof(struct Recipe), 1, file);

	fclose(file);
}

void convertRecipeNameinFileName(char* buff)
{
	char* find;
	char* findSpace;

	if (buff)
	{
		do
		{
			findSpace = 0;
			find = strchr(buff, '\n');
			findSpace = strchr(buff, ' ');
			if (find)
			{
				*find = 0;
			}
			if (findSpace)
			{
				*findSpace = '_';
			}
		} while (findSpace != NULL);
	}
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void viewAllRecipe(char* fileName)
{
	cleanInput();
	WIN32_FIND_DATAA found;
	HANDLE findResult = FindFirstFileA("d:\\recipe\\*.bin", &found);
	
	if (findResult == INVALID_HANDLE_VALUE)
	{
		printf("This directory contains no files\n");
	}
	else
	{
		do
		{
			if (found.nFileSizeLow != NULL)
			{
				printf("%s\n", found.cFileName);
			}
		} while (FindNextFileA(findResult, &found));

		char buff[NAME_SIZE];
		
		printf("Enter file name: ");
		scanf("%s", &buff);
		cleanInput();
		strcat(fileName, buff);

		findResult = FindFirstFileA("d:\\recipe\\*.bin", &found);
		do
		{
			if (strcmp(found.cFileName, buff) == NULL)
			{
				SYSTEMTIME time;
				FileTimeToSystemTime(&found.ftLastAccessTime, &time);
				printf("The creation date of the recipe: ");
				printf("[%d.%d.%d]\n", time.wDay, time.wMonth, time.wYear);
			}
		} while (FindNextFileA(findResult, &found));
	}
	FindClose(findResult);
}

void viewRecipe()
{
	char fileName[NAME_SIZE] = "d:\\\\recipe\\\\";
	struct Recipe recipe;

	viewAllRecipe(fileName);

	FILE* file = fopen(fileName, "rb");

	if (file == NULL)
	{
		printf("This file is not found");
	}
	else
	{
		fread(&recipe, sizeof(struct Recipe), 1, file);
		printf("%s", HEDDER_NAME);
		printf("%s", recipe.Name);
		printf("%s", HEDDER_TEXT);
		printf("%s", recipe.Text);
		printf("%s", HEDDER_RATING);
		printf("%i\n", recipe.Rating);
	}
	fclose(file);
}

void editRecipe()
{
	char fileName[NAME_SIZE] = "d:\\\\recipe\\\\";
	struct Recipe recipe;

	viewAllRecipe(fileName);

	FILE* file = fopen(fileName, "rb");

	if (file == NULL)
	{
		printf("This file is not found");
	}
	else
	{
		fread(&recipe, sizeof(struct Recipe), 1, file);
		memset(recipe.Text, 0, TEXT_SIZE);
		printf("Enter the text of recipe: ");
		fgets(recipe.Text, TEXT_SIZE, stdin);
		file = fopen(fileName, "wb");
		fwrite(&recipe, sizeof(struct Recipe), 1, file);
	}
	fclose(file);
}

void deleteRecipe()
{
	char fileName[NAME_SIZE] = "d:\\\\recipe\\\\";

	viewAllRecipe(fileName);

	FILE* file = fopen(fileName, "rb");

	if (file == NULL)
	{
		printf("This file is not found");
	}
	else
	{
		file = fopen(fileName, "wb");
		int rc = remove(fileName);
		if (rc)
		{ 
			perror("remove");
		}
		printf("Removed %s", fileName);
	}
	fclose(file);
}
