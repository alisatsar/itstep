#include <stdio.h>
#include <stdlib.h>

void fillMatrix(float matrix[5][12]);
void printMatrix(float matrix[5][12]);

int main()
{
	float matrix[5][12];

	srand(matrix[0][0]);

	fillMatrix(matrix);

	printMatrix(matrix);

	int year;
	int month;
	float subtot;
	float total;

	printf("ГОД КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
	for (year = 0, total = 0; year < 5; year++)
	{
		for (month = 0, subtot = 0; month < 12; month++)
		{
			subtot += matrix[year][month];
		}
		printf("%i %.2f\n", 2010 + year, subtot);
		total = total + subtot;
	}
	printf("Averege counter is %.2f\n", total / 5);

	printf("JAN	FEB	MAR	APR	MAY	JUN	JUL	AVG	SEN	OCT	NOV	DEC");
	for (month = 0; month < 12; month++)
	{
		for (year = 0, subtot = 0; year < 5; year++)
		{
			subtot = subtot + matrix[year][month];
		}
		printf("%.2f	", subtot / 5);
	}

}

void fillMatrix(float matrix[5][12])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			matrix[i][j] = rand() % 10 / 0.3;
		}
	}
}

void printMatrix(float matrix[5][12])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			printf("matrix[%i][%i] = %.1f\n", i, j, matrix[i][j]);
		}
	}
}
