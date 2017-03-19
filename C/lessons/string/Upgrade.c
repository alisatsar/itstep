#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum MenuAddress
{
	AddUser = 1,
	AddPhone = 2,
	Exit = 3
};

void clearArray(char matrix[][3][256], int col, int row);
void getUser(char* title, char* user);
void printArray(char addressBook[][3][256], int col, int row);

int main()
{
	char addressBook[2][3][256];
	enum MenuAddress menuAddress;
	
	clearArray(addressBook, 2, 3);
	printArray(addressBook, 2, 3);

	int user = 0;
	int phone = 0;
	
	scanf("%i", &menuAddress);

	/*do {
		menuAddress = getchar();
	} while (menuAddress != '\n' && menuAddress != EOF);*/
	getUser("name", addressBook[0][user]);
	switch (menuAddress)
	{
	case AddUser:
		getUser("name", addressBook[0][user]);
		user++;
		break;
	case AddPhone:
		getUser("name", addressBook[1][phone]);
		phone++;
		break;
	}
		
	printArray(addressBook, 2, 3);
}

void getUser(char* title, char* user)
{
	printf("Enter %s: ", title);

	char buffer[256];
	fgets(buffer, 256, stdin);
	strcpy(user, buffer);

	while (*user != 0)
	{
		if (*user == '\n')
		{
			*user = 0;
		}
		user++;
	}
}

void clearArray(char matrix[][3][256], int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			matrix[i][j][0] = 0;
		}
	}
}

void printArray(char addressBook[][3][256], int col, int row)
{
	printf("Name\tPhone\n");
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%s\t", addressBook[j][i]);
		}
		printf("\n");
	}
}
