#include "Stack.h"
#include <iostream>

int main()
{
	Stack2 s1;
	
	s1.Push(11);
	s1.Push(22);
	s1.Push(33);

	std::cout << std::endl << s1.Pop();
  
	std::cout << std::endl << s1.Pop();

	std::cout << std::endl << s1.Pop();

	std::cout << std::endl << s1.Pop();

	return 0;
}
