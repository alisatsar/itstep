#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
bool getFileName(char const* filePath,
    char* fileName);
 
int main()
{
    char* fileName = malloc(256);
    if (getFileName("c:\\sdsdf",
        fileName))
    {
        printf("filePath: %s\n", "c:\\sdsdf");
        printf("fileName: %s", fileName);
    }
}
 
bool getFileName(char const* filePath,
    char* fileName)
{
    char* found = filePath;
    char* tmp = NULL;
    do
    {
        tmp =
            strstr(found, "\\");
 
        if (tmp != NULL)
        {
            found = tmp + 1;
        }
    } while (tmp);
 
    if (found != NULL && found != filePath)
    {
        strcpy(fileName, found);
        return true;
    }
    return false;
}
