/*#include <stdio.h>

#define COUNT 5

int main()
{
	int array[COUNT] = { 4, 3, 1, 5, 2 };

	for (int i = 0; i < COUNT - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < COUNT; j++)
		{
			if (array[minIndex] > array[j])
			{
				minIndex = j;
			}
			
		}
		if (minIndex != i)
		{
			int c = array[minIndex];
			array[minIndex] = array[i];
			array[i] = c;
		}
	}
}*/

/*#include <stdio.h>

#define COUNT 5

int main()
{
	int matrix[2][5] = { { 0, 1, 2, 3, 4 }, { 5, 6, 7, 8, 9 } };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j <5 ; j++)
		{
			printf("matrix[%i][%i] = %i\n", i, j, matrix[i][j]);
		}
	}
}

void printArray(int matrix[2][5], int row, int column)
{

}*/

/*#include <stdio.h>

#define COUNT_ROW 2
#define COUNT_COLUMN 5

void getArray(int matrix[2][5], int row, int column);
void printArray(int matrix[2][5], int row, int column);

int main()
{
	int matrix[COUNT_ROW][COUNT_COLUMN];

	getArray(matrix, COUNT_ROW, COUNT_COLUMN);
	printArray(matrix, COUNT_ROW, COUNT_COLUMN);
}

void getArray(int matrix[2][5], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <column; j++)
		{
			printf("Enter array row:");
			scanf("%i", &matrix[i][j]);
		}
	}
}

void printArray(int matrix[2][5], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <column; j++)
		{
			printf("matrix[%i][%i] = %i\n", i, j, matrix[i][j]);
		}
	}
}*/

#include <stdio.h>
#include <limits.h>

#define COUNT_ROW 2
#define COUNT_COLUMN 3
#define COUNT_COLUMN_B 4

void getArray(int array[], int count);
void getMatrix(int arrayA[], int arrayB[], int matrix[COUNT_ROW][COUNT_COLUMN_B], int row, int column);
void printArray(int matrix[2][4], int row, int column);

int main()
{
	int arrayA[COUNT_COLUMN];
	int arrayB[COUNT_COLUMN_B];
	int matrix[COUNT_ROW][COUNT_COLUMN_B];

	getArray(arrayA, COUNT_COLUMN);
	printf("\n");
	getArray(arrayB, COUNT_COLUMN_B);

	getMatrix(arrayA, arrayB, matrix, COUNT_ROW, COUNT_COLUMN_B);

	printArray(matrix, COUNT_ROW, COUNT_COLUMN_B);

}

void getArray(int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("Enter array row:");
		scanf("%i", &array[i]);
	}
}

void getMatrix(int arrayA[], int arrayB[], int matrix[COUNT_ROW][COUNT_COLUMN_B], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < column; j++)
			{
				if (j == column - 1)
				{
					matrix[i][j] = INT_MIN;
				}
				else
				{
					matrix[i][j] = arrayA[j];
				}
			}
		}
		if (i == 1)
		{
			for (int j = 0; j < column; j++)
			{
				matrix[i][j] = arrayB[j];
			}
		}
	}
}

void printArray(int matrix[2][4], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <column; j++)
		{
			printf("matrix[%i][%i] = ", i, j);
			if (matrix[i][j] == INT_MIN)
			{
				printf("-\n");
			}
			else
			{
				printf("%i\n", matrix[i][j]);
			}

		}
	}
}
