#include <stdio.h>
/*#define YEARS_COUNT 3

int main()
{
	int const count = 3;
	int e[YEARS_COUNT] = { 2000, 2001, 2003 };

}*/

#define COUNT 7

int main()
{
	float count[COUNT];
	printf("Ånter the temperature in Celsius in day 1: ");
	scanf("%f", &count[0]);
	printf("Ånter the temperature in Celsius in day 2: ");
	scanf("%f", &count[1]);
	printf("Ånter the temperature in Celsius in day 3: ");
	scanf("%f", &count[2]);
	printf("Ånter the temperature in Celsius in day 4: ");
	scanf("%f", &count[3]);
	printf("Ånter the temperature in Celsius in day 5: ");
	scanf("%f", &count[4]);
	printf("Ånter the temperature in Celsius in day 6: ");
	scanf("%f", &count[5]);
	printf("Ånter the temperature in Celsius in day 7: ");
	scanf("%f", &count[6]);

	float summ = 0;

	for (int i = 0; i < COUNT; i++)
	{
		summ += count[i];
	}
		
	float min = 0;

	for (int i = 1; i < COUNT; i++)
	{
		if (count)
	}

	printf("the average temperature is %f\n", summ / COUNT);
	printf("the minimal temperature is %f\n", min);
}
