#include <iostream>
#include <vector>
#include "SafeVector.h"
#include <exception>
 
int main()
{
    SafeVector<int> v1;
 
    //int b = 3;
    //v1.PushBack(b);
    try
    {
        v1.PopBack();
       
    }
    catch (std::exception ex)
    {
        std::cout << ex.what() << std::endl;
    }
 
    try
    {
        std::cout << v1[3];
    }
    catch (std::exception ex)
    {
        std::cout << ex.what() << std::endl;
    }  
 
    return 0;
}
