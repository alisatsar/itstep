#include <stdio.h>
 
typedef void(*SortTypeFunc)(int*, int);
 
void modifyArray(int* array, int size,
    SortTypeFunc sortFunctions[], int sortFunctionsSize)
{
    for (int i = 0; i < sortFunctionsSize; i++)
    {
        SortTypeFunc foo = sortFunctions[i];
        foo(array, size);
    }
}
 
void sortBubble(int* array, int size)
{
    printf("sortBubble\n");
}
 
void sortSelection(int* array, int size)
{
    printf("sortSelection\n");
}
 
void sortInsertion(int* array, int size)
{
    printf("sortInsertion\n");
}
 
void reverse(int* array, int size)
{
    printf("reverse\n");
}
 
void main()
{
    int array[10];
 
    SortTypeFunc functions[10];
    functions[0] = sortBubble;
    functions[1] = sortSelection;
    functions[2] = sortInsertion;
    functions[3] = sortBubble;
    functions[4] = sortSelection;
    functions[5] = sortInsertion;
    functions[6] = sortBubble;
    functions[7] = sortSelection;
    functions[8] = sortInsertion;
    functions[9] = reverse;
 
    modifyArray(array, 10, functions, 10);
}
