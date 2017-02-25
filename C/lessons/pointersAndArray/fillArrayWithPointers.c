#include <stdio.h>
#include <stdlib.h>
 
void fillArray(int* array,
    int arraySize)
{
    for (int i = 0;
        i < arraySize;
        i++, array++)
    {
        *(array) = rand();
    }
}
 
void printArray(int* array,
    int arraySize)
{
    int* end = array + arraySize - 1;
    int* begin = array;
    for (int i = 0;
        i < arraySize;
        i++, begin++)
    {
        printf("%i, ", *(begin));
    }
    for (int i = 0;
        i < arraySize;
        i++, end--)
    {
        printf("%i, ", *(end));
    }
}
 
void main()
{
    int array[10];
    fillArray(array, 10);
    printArray(array, 10);
}
