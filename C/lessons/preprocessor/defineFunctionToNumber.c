#include <stdio.h>
 
void max1()
{
    printf("%s", __FUNCTION__);
}
 
void max2()
{
    printf(__FUNCTION__);
}
 
void max3()
{
    printf(__FUNCTION__);
}
 
void min1() { printf(__FUNCTION__); }
void min2() { printf(__FUNCTION__); }
void min3() { printf(__FUNCTION__); }
 
#define VERSION 2
 
#define EXEC2(foo, version) foo ## version();
#define EXEC1(foo, version) EXEC2(foo, version)
#define EXEC(foo) EXEC1(foo, VERSION)
 
int main(int argCount, char* argValues[])
{
    EXEC(max);
    EXEC(min);
}
