#include <fstream> // Для файлового ввода/вывода
#include <iostream>
#include <string>

int main()
{
	char ch = 'x';
	int j = 77;
	double d = 6.02;
	std::string str1 = "Kafka";
	std::string str2 = "Proust";

	std::ifstream inFile("newFile.txt");		// создать объект ifstream
												// извлечь (прочесть) из него данные 

	inFile >> ch >> j >> d >> str1 >> str2;

	std::cout << ch << std::endl << j << std::endl
		<< d << std::endl << str1 << std::endl << str2 << std::endl;

}
