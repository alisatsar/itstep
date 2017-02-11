#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
#define ARRAY_SIZE 10
 
void printArray(float const array[], int arraySize);
void sortBubble(float array[], int arraySize,
    enum SortResult sortResults[]);
void swapElements(float array[], int index1, int index2);
void fillRandomArray(float array[], int arraySize);
 
enum SortResult
{
    SortResultSwapCount = 0,
    SortResultCompareCount,
    SortResultCount
};
 
int main()
{
    srand(time(0));
 
    float array[ARRAY_SIZE];
    fillRandomArray(array, ARRAY_SIZE);
 
    printArray(array, ARRAY_SIZE);
 
    enum SortResult sortResults[SortResultCount];
    sortBubble(array, ARRAY_SIZE, sortResults);
    printf("swapCount = %i, compareCount = %i\n",
        sortResults[SortResultSwapCount],
        sortResults[SortResultCompareCount]);
 
    printArray(array, ARRAY_SIZE);
}
 
void printArray(float const array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%5.1f", array[i]);
    }
    printf("\n");
}
 
void sortBubble(float array[], int arraySize,
    enum SortResult sortResults[])
{
    sortResults[SortResultCompareCount] = 0;
    sortResults[SortResultSwapCount] = 0;
 
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = 0; j < arraySize - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swapElements(array, j, j + 1);
                sortResults[SortResultSwapCount]++;
            }
 
            sortResults[SortResultCompareCount]++;
        }
        if (sortResults[SortResultSwapCount] == 0)
        {
            break;
        }
    }
}
 
void swapElements(float array[], int index1, int index2)
{
    float buffer = array[index1];
    array[index1] = array[index2];
    array[index2] = buffer;
}
 
void fillRandomArray(float array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % 200 / 10;
    }
}
