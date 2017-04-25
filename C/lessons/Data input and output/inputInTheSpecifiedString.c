#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
 
#define FILE_SIZE 170
#define STRING_SIZE 50
 
enum StringPositions
{
    FirstNamePosition = 0,
    LastNamePosition = 57,
    MiddleNamePosition = 119,
};
 
void writeString(char* string, int offset,
    FILE* f)
{
    fseek(f, offset, SEEK_SET);
    fwrite(string, STRING_SIZE, 1, f);
}
 
void readString(char* string, int offset,
    FILE* f)
{
    fseek(f, offset, SEEK_SET);
    fread(string, STRING_SIZE, 1, f);
}
 
int main()
{
    setlocale(LC_ALL, "rus");
    FILE* f = fopen("d:\\t.bin", "rb");
    char* buff = malloc(FILE_SIZE);
 
    if (f == NULL)
    {
        // need to write
        f = fopen("d:\\t.bin", "wb");
        memset(buff, 0, FILE_SIZE);
        fwrite(buff, FILE_SIZE, 1, f);
 
        strcpy(buff, "Sergey");
        writeString(buff, FirstNamePosition,
            f);
        strcpy(buff, "Gradovich");
        writeString(buff, LastNamePosition,
            f);
        strcpy(buff, "Pavlovich");
        writeString(buff, MiddleNamePosition,
            f);
    }
    else
    {
        // need to read
        readString(buff, FirstNamePosition, f);
        printf("FirstName: %s\n", buff);
        readString(buff, LastNamePosition, f);
        printf("LastName: %s\n", buff);
        readString(buff, MiddleNamePosition, f);
        printf("MiddleName: %s\n", buff);
 
    }
 
    fclose(f);
}
