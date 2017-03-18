#include <stdio.h>
 
void strCopy(char* from, char* to)
{
    while (*from != 0 && *from != '\n')
    {
        *to = *from;
        from++;
        to++;
    }
    *to = 0;
}
 
void clearArray(char array[][256],
    int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i][0] = 0;
    }
}
 
void printArray(char array[][256],
    int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("nameCell[%i]: %s\n",
            i, array[i]);
    }
}
 
int main()
{
    char nameColumn[10][256];
    clearArray(nameColumn, 10);
    // char**
    char name[256];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter name: ");
        fgets(nameColumn[i], 256, stdin);
    }
   
    printArray(nameColumn, 10);
}
