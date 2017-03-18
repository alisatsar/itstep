#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
void cleanString(char* string)
{
    while (*string != 0)
    {
        if (*string == '\n')
        {
            *string = 0;
        }
        string++;
    }
}
 
void copyStringAndClean(char* to, char* from)
{
    strcpy(to, from);
    cleanString(to);
}
 
void clearArray(char array[][10][256],
    int colCount, int rowCount)
{
    for (int col = 0; col < colCount;
        col++)
    {
        for (int row = 0; row < rowCount;
            row++)
        {
            array[col][row][0] = 0;
        }
    }
}
 
void printArray(char array[][10][256],
    int colCount, int rowCount)
{
    printf("Name\tPhone\n");
    for (int row = 0; row < rowCount;
        row++)
    {
        for (int col = 0; col < colCount;
            col++)
        {
            printf("%s\t",
                array[col][row]);
        }
        printf("\n");
    }
}
 
void getUser(char* title, char* user)
{
    // "Enter " + title + ": "
    char text[50];
    strcpy(text, "Enter ");
    strcat(text, title);
    strcat(text, ": ");
    printf(text);
 
    printf("Enter %s: ", title);
 
    char buffer[256];
    fgets(buffer, 256, stdin);
    copyStringAndClean(user, buffer);
}
 
int main()
{
    char addressBook[2][10][256];
    clearArray(addressBook, 2, 10);
 
    for (int user = 0; user < 2; user++)
    {
        getUser("name", addressBook[0][user]);
        getUser("phone", addressBook[1][user]);
    }
   
    printArray(addressBook, 2, 2);
}
