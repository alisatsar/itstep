#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
 
#define ARRAY_SIZE 20000
 
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
        int randNum = -ARRAY_SIZE*7 + rand() % (ARRAY_SIZE + 1)*7;
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
    int const startTime = time(0);
    int array[ARRAY_SIZE];
    srand(array);
    fillArray(array, ARRAY_SIZE);
 
    //printArray(array, ARRAY_SIZE);
    int const endTime = time(0);
    int const seconds = endTime - startTime;
 
    printf("\nSeconds: %i", seconds);
}
