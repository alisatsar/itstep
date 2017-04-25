#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
 
#define FILE_SIZE 170
#define STRING_SIZE 50
 
struct FIO
{
    char FirstName[53];
    int k;
    char LastName[58];
    char MiddleName[50];
    bool b;
};
 
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
    FILE* f = fopen("d:\\t.bin", "wb");
 
    /*double pi = 3.14;
    fwrite(&pi, sizeof(double), 1, f);
    long long n = 2378462378;
    fwrite(&n, sizeof(long long), 1, f);*/
   
    struct FIO fio = { "Vasya", 678, "Pupkin",
        "Vasilyevich", true };
    fwrite(&fio, sizeof(struct FIO),
        1, f);
 
    fclose(f);
    ///////////////////
 
    f = fopen("d:\\t.bin", "rb");
 
    /*double pi2;
    fread(&pi2, sizeof(double), 1, f);
    long long n2;
    fread(&n2, sizeof(long long), 1, f);*/
 
    struct FIO fio2;
    fread(&fio2, sizeof(struct FIO),
        1, f);
 
    printf("%s\n", fio2.FirstName);
    printf("%s\n", fio2.LastName);
    printf("%s\n", fio2.MiddleName);
    printf("%i\n", fio2.k);
    printf("%i\n", fio2.b);
 
    fclose(f);
}
