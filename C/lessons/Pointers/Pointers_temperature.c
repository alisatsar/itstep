#include <stdio.h>
#include <stdlib.h>

void getData(float *t1, float *t2, float *t3, float *t4, float *t5);
void printData(float t1, float t2, float t3, float t4, float t5);

int main()
{
	float t1;
	float t2;
	float t3;
	float t4;
	float t5;
	
	srand(&t1);

	getData(&t1, &t2, &t3, &t4, &t5);

	printData(t1, t2, t3, t4, t5);
}

void getData(float *t1, float *t2, float *t3, float *t4, float *t5)
{
	do
	{
		printf("t1 =");
		scanf("%f", t1);
	} while (*t1 > 32 || *t1 < 0);
	
	do
	{
		printf("t2 =");
		scanf("%f", t2);
	} while (*t2 > 32 || *t2 < 0);

	do
	{
		printf("t3 =");
		scanf("%f", t3);
	} while (*t3 > 32 || *t3 < 0);

	do
	{
		printf("t4 =");
		scanf("%f", t4);
	} while (*t4 > 32 || *t4 < 0);

	do
	{
		printf("t5 =");
		scanf("%f", t5);
	} while (*t5 > 32 || *t5 < 0);
}

void printData(float t1, float t2, float t3, float t4, float t5)
{
	printf("t1 = %.2f\n", t1);
	printf("t2 = %.2f\n", t2);
	printf("t3 = %.2f\n", t3);
	printf("t4 = %.2f\n", t4);
	printf("t5 = %.2f\n", t5);
}
