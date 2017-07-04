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

	std::ofstream outFile("newFile.txt");

	outFile << ch << j << ' ' << d << str1 << ' ' << str2;

	std::cout << "File has been writed";
}
