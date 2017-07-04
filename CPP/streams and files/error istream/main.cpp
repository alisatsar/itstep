#include <iostream>

int main()
{
	int i = 0;
	while (true) //цикл до тех пор пока ввод не будет корректным
	{
		std::cout << "\nEnter number: ";
		std::cin.unsetf(std::ios::skipws);	//не игнорировать разделители 

		std::cin >> i;

		if (std::cin.good())	//если нет ошибок
		{
			std::cin.ignore(10, '\n');	//удалить разделитель строк
			break;
		}

		std::cin.clear();		//очистить биты ошибок
		std::cout << "the wrong input data";
		
		std::cin.ignore(10, '\n');	//приводит к считыванию до 10 символов,
		//включая ограничитель '\n', и удалению их из входного потока.
	}

	std::cout << "integer number: " << i;	//целое без ошибок
	return 0;
}
