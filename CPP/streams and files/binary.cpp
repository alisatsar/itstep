#include <fstream> // Для файлового ввода/вывода
#include <iostream>

const int MAX = 100;
int buff[MAX];

int main()
{
	for (int i = 0; i < MAX; i++)
	{
		buff[i] = i;
	}

	std::ofstream oFile("Edata.dat", std::ios::binary);

	oFile.write(reinterpret_cast<char*>(buff), MAX * sizeof(int)); //для того, чтобы буфер данных типа int
																	//выглядел для функций read() и write() как буфер типа char. 
	oFile.close();

	for (int i = 0; i < MAX; i++)
	{
		buff[i] = 0;
	}

	std::ifstream iFile("Edata.dat", std::ios::binary);

	iFile.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));

	for (int j = 0; j < MAX; j++)
	{
		if (buff[j] != j)
		{
			std::cerr << "Uncorrect data\n";
			return 1;
		}
	}

	std::cout << "Correct data\n";
	return 0;
}
