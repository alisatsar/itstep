#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define ARRAY_SIZE 20
 
bool isArrayContainsValue(int array[], int position,
    int value)
{
    int j = position - 1;
    bool foundExisting = false;
    while (j >= 0)
    {
        if (array[j] == value)
        {
            foundExisting = true;
            break;
        }
        --j;
    }
    return foundExisting;
}
 
void fillArray(int array[], int arraySize)
{
    int i = 0;
 
    int count = 0;
    while (i < arraySize)
    {
        int randNum = -100 + rand() % 201;
        if (randNum % 7 != 0)
        {
            ++count;
            continue;
        }
       
        if (isArrayContainsValue(array, i, randNum))
        {
            continue;
        }
        array[i] = randNum;
 
        ++i;
        ++count;
    }
    printf("Cycle count: %i\n", count);
}
 
void printArray(int array[],
    int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i, ", array[i]);
    }
}
 
void main()
{
    int array[ARRAY_SIZE];
    srand(array);
    fillArray(array, ARRAY_SIZE);
 
    printArray(array, ARRAY_SIZE);
}
