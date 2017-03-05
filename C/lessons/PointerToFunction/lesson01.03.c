#include <stdio.h>
 
typedef void(*SortTypeFunc)(int*, int);
 
void modifyArray(int* array, int size,
    SortTypeFunc sort1,
    SortTypeFunc sort2,
    SortTypeFunc sort3)
{
    sort1(array, size);
    sort2(array, size);
    sort3(array, size);
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
 
void main()
{
    int array[10];
 
    modifyArray(array, 10, sortBubble,
        sortInsertion, sortSelection);
}
