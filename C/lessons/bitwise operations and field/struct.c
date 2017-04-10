#include <stdio.h>

struct CarCondition
{
	char Transmission : 1; //поле занимает один бит а не 8
	char Type : 1;
	char Electro : 1;
	char Wheel : 1;
};

union Car
{
	char Number;
	struct CarCondition car;
};

void printCar(struct CarCondition car);

int main()
{
	struct CarCondition car;
	
	car.Transmission = 1;
	car.Type = 1;
	car.Electro = 0;
	car.Wheel = 1;

	printCar(car);
}

void printCar(struct CarCondition car)
{
	if (car.Transmission)
	{
		printf("Mehanical\n");
	}
	else
	{
		printf("Automatic\n");
	}
	if (car.Type)
	{
		printf("Cargo\n");
	}
	else
	{
		printf("Passenger\n");
	}
	if (car.Electro)
	{
		printf("Electro\n");
	}
	else
	{
		printf("Not electro\n");
	}
	if (car.Wheel)
	{
		printf("Left\n");
	}
	else
	{
		printf("Right\n");
	}
}
