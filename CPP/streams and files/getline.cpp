#include <fstream> // Для файлового ввода/вывода
#include <iostream>

int main()
{
	std::ofstream file("Test.txt", std::ios::out | std::ios::trunc);

	file << "Hello world!\n" << "How are you?\n" << "I\'m fine, thank you, and you?\n";

	const int MAX = 80;
	char buffer[MAX];

	file.close(); //Закрыть файл

	std::ifstream ifile("Test.txt");
	
	//std::cout << ifile.rdbuf();      // или передать его буфер в cout 

	while (!ifile.eof()) //цикл до EOF
	{
		ifile.getline(buffer, MAX);
		std::cout << buffer << std::endl;
	}

	return 0;
}
