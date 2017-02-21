#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
bool getData(int* t1, int* t2,
    int* t3, int* t4, int* t5)
{
    printf("Please enter t1: ");
    scanf("%i", t1);
    if (*t1 < 0 || *t1 > 32)
    {
        return false;
    }
    if (t2 == NULL)
    {
        return false;
    }
    printf("Please enter t2: ");
    scanf("%i", t2);
    printf("Please enter t3: ");
    scanf("%i", t3);
    printf("Please enter t4: ");
    scanf("%i", t4);
    printf("Please enter t5: ");
    scanf("%i", t5);
 
    return true;
}
 
void printData(int* t1, int* t2,
    int* t3, int* t4, int* t5)
{
    printf("t1: %i\n", *t1);
    printf("t2: %i\n", *t2);
    printf("t3: %i\n", *t3);
    printf("t4: %i\n", *t4);
    printf("t5: %i\n", *t5);
}
 
int main()
{
    int t1;
    int* pt1 = &t1;
    int* pt2 = NULL;
    int* pt3 = NULL;
    int* pt4 = NULL;
    int* pt5 = NULL;
 
    bool result = getData(pt1, pt2, pt3,
        pt4, pt5);
    if (result != true)
    {
        printf("Error");
        return 1;
    }
    else
    {
        printData(t1, pt2, pt3, pt4, pt5);
    }
}
 
void getRandom(int* random)
{
    *random = rand();
}
