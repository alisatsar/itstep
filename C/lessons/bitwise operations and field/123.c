#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
 
struct NumberFlags
{
    unsigned char b0 : 1; //выделяй не 8 байт, а один
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};
 
union Number
{
    char number;
    struct NumberFlags numberFlags;
};
 
 
 
void main()
{
    union Number number;
    number.number = 123;
 
    printf("%i", number.numberFlags.b7);
    printf("%i", number.numberFlags.b6);
    printf("%i", number.numberFlags.b5);
    printf("%i", number.numberFlags.b4);
    printf("%i", number.numberFlags.b3);
    printf("%i", number.numberFlags.b2);
    printf("%i", number.numberFlags.b1);
    printf("%i", number.numberFlags.b0);
 
}

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
 
void main()
{
    unsigned int number = 123;
 
    for (int i = 31; i >= 0; i--)
    {
        printf("%i", (number & (1 << i)) ? 1 : 0);
    }
 
}
