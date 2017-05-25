#include <iostream>

int main()
{
	int count = 10;
	
	std::cout << "count = " << count << std::endl; //вывод числа 10
	std::cout << "++count " << ++count << std::endl; //вывод числа 11
	std::cout << "count" << count << std::endl; //вывод числа 11
	std::cout << "count++" << count++ << std::endl; //вывод числа 11
	std::cout << "count" << count << std::endl; //вывод числа 12

	return 0;
}
