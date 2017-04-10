#include <stdio.h>

enum CarCondition
{
	Transmission = 1,
	Type = 1 << 1,
	Electro = 1 << 2,
	Wheel = 1 << 3
};

void printCar(char car);

int main()
{
	char car = 0;
	
	car |= Wheel | Type;  //car = car | Type | Wheel;
	printf("%i\n", car);
	//car &= ~(Type); 	//выключение байта

	car &= ~(Type) & ~Wheel;
	printCar(car);
}

void printCar(char car)
{
	if (car & Transmission)
	{
		printf("Mehanical\n");
	}
	else
	{
		printf("Automatic\n");
	}
	if (car & Type)
	{
		printf("Cargo\n");
	}
	else
	{
		printf("Passenger\n");
	}
	if (car & Electro)
	{
		printf("Electro\n");
	}
	else
	{
		printf("Not electro\n");
	}
	if (car & Wheel)
	{
		printf("Left\n");
	}
	else
	{
		printf("Right\n");
	}
}
