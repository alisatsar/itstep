#include "counten.h"
#include <iostream>

int main()
{
	CountDn c1;
	CountDn c2(100);
	std::cout << "\nc1 = " << c1.GetCount();

	++c1; ++c1; ++c1;                  

	--c2; --c2;                        

	CountDn c3;  

	return 0;
}
