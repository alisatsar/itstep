/*Задание 2:
Написать программу, которая хранит информацию об автомобиле(марка, модель, цвет
(enum), тип топлива(enum) и год) в динамическом массиве.Пользователь определяет
размерность массива и вводит 5 автомобилей.Реализовать возможность поиска всех
автомобилей младше определенного года.*/
#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
enum Color
{
    ColorRed = 1,
    ColorGreen,
    ColorBlack,
    ColorWhile,
    ColorGrey
};
 
enum FuelType
{
    FuelTypeBenzine80 = 1,
    FuelTypeBenzine92,
    FuelTypeBenzine95,
    FuelTypeGas,
    FuelTypeDiesel
};
 
struct Car
{
    char* Brand;
    char* Model;
    enum Color Color;
    enum FuelType FuelType;
    int Year;
};
 
void getString(char* message, char* st, int maxStringSize);
void cleanInput();
void printCarsFilteredByYear(struct Car* cars, int carsCount, int year);
void getInt(char* message, int* value);
 
int main()
{
    printf("Please enter car count: ");
    int carCount;
    scanf("%i", &carCount);
    cleanInput();
   
    struct Car* car = malloc(carCount * sizeof(struct Car));
 
    int i = 0;
    while (i < carCount)
    {
        printf("=== Please enter #%i car: ===\n", i + 1);
        car[i].Brand = malloc(30);
        getString("Brand: ", car[i].Brand, 30);
        car[i].Model = malloc(30);
        getString("Model: ", car[i].Model, 30);
        getInt("Year: ", (int*)&car[i].Year);
        getInt("Color: ", (int*)&car[i].Color);
        getInt("FuelType: ", (int*)&car[i].FuelType);
        cleanInput();
        i++;
    }
 
    printf("Please enter the year: ");
    int year;
    scanf("%i", &year);
 
    printCarsFilteredByYear(car, carCount, year);
    system("pause");
}
 
void getString(char* message, char* st, int maxStringSize)
{
    char* find;
 
    printf("%s", message);
    char* result = fgets(st, maxStringSize, stdin);
    if (result != NULL)
    {
        find = strchr(st, '\n');
        if (find != NULL)
        {
            *find = 0;
        }
        else
        {
            cleanInput();
        }
    }
}
 
void getInt(char* message, int* value)
{
    printf("%s", message);
    scanf("%i", value);
}
 
void cleanInput()
{
    char ch;
    do
    {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
}
 
void printCar(struct Car* car)
{
    printf("Brand:\t%s\n", car->Brand);
    printf("Model:\t%s\n", car->Model);
    printf("FuelType:\t%i\n", car->FuelType);
    printf("Color:\t%i\n", car->Color);
    printf("Year:\t%i\n\n", car->Year);
}
 
void printCarsFilteredByYear(struct Car* cars, int carsCount, int year)
{
    for (int i = 0; i < carsCount; i++)
    {
        if (cars[i].Year > year)
        {
            printCar(&cars[i]);
        }
    }
}
