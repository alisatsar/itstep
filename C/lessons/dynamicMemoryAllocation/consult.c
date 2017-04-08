#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 
struct Car
{
    char* CarPlate;
    struct Car* Next;
    struct Car* Prev;
};
 
struct Car* init(char* carPlate);
struct Car* add(struct Car* lineHead, char* carPlate);
struct Car* get(struct Car* lineHead, char* carPlate,
    bool* found);
 
int main()
{
    struct Car* lineHead = init("9236 HX-7");
 
    struct Car* lineTail = lineHead;
    lineTail = add(lineHead, "1245 HX-5");
    lineTail = add(lineHead, "5678 PC-7");
    lineTail = add(lineHead, "7678 PC-7");
    lineTail = add(lineHead, "8678 PC-7");
    lineTail = add(lineHead, "9678 PC-7");
 
    char* carPlate = malloc(10);
    bool found = false;
    do
    {
        lineHead = get(lineHead, carPlate, &found);
        if (found)
        {
            printf("Car plate: %s\n", carPlate);
        }
    } while (found);
 
}
 
struct Car* init(char* carPlate)
{
    struct Car* car =
        malloc(sizeof(struct Car));
    car->CarPlate = malloc(10);
    strcpy(car->CarPlate, carPlate);
    car->Next = NULL;
    car->Prev = NULL;
 
    return car;
}
 
struct Car* get(struct Car* lineHead,
    char* carPlate, bool* found)
{
    if (lineHead == NULL)
    {
        *found = false;
        return NULL;
    }
    strcpy(carPlate, lineHead->CarPlate);
    *found = true;
   
    if (lineHead->Prev)
    {
        lineHead = lineHead->Prev;
        free(lineHead->Next);
        lineHead->Next = NULL;
    }
    else
    {
        free(lineHead);
        lineHead = NULL;
    }
    return lineHead;
}
 
struct Car* add(struct Car* lineHead,
    char* carPlate)
{
    struct Car* lineTail = lineHead;
    while (lineTail->Prev != NULL)
    {
        lineTail = lineTail->Prev;
    }
    lineTail->Prev = init(carPlate);
    lineTail->Prev->Next = lineTail;
   
    lineTail = lineTail->Prev;
 
    return lineTail;
}
