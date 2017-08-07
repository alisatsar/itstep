#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
	double x, y;
	std::cout << "Multiplication of two floatinng point values" << std::endl;

	std::cout << "First operand: ";

	if (!(std::cin >> x))
	{
		std::cerr << "error while reading the first floating value" << std::endl;
		return EXIT_FAILURE;            //макрос из std::exit сигнализирующий об безуспешном выполнении программы
	}

	std::cout << "Second operand: ";

	if (!(std::cin >> y))
	{
		std::cerr << "Error while reading the second floating value" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << x << " Times: " << y << " Equals " << x * y << std::endl;
}
