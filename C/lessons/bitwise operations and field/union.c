#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
 
struct CarFlags
{
    char Manual : 1;
    char Passenger : 1;
    char Electric : 1;
    char RightWeel : 1;
};
 
union Car
{
    char number;
    struct CarFlags carFlags;
};
 
void printCar(struct CarFlags car)
{
    if (car.Manual)
    {
        printf("Manual\n");
    }
    else
    {
        printf("Automatic\n");
    }
    if (car.Electric)
    {
        printf("Electric\n");
    }
    else
    {
        printf("Non electric\n");
    }
    if (car.RightWeel)
    {
        printf("Right wheel\n");
    }
    else
    {
        printf("Left wheel\n");
    }
    if (car.Passenger)
    {
        printf("Passenger\n");
    }
    else
    {
        printf("Cargo\n");
    }
}
 
void main()
{
    union Car car;
    car.carFlags.RightWeel = 1;
    car.carFlags.Electric = 0;
    car.carFlags.Passenger = 0;
    car.carFlags.Manual = 0;
 
    printf("%i", car.number);
 
    printf("Car size: %i", sizeof(struct CarFlags));
}
