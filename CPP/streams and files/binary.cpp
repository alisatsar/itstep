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

/*#include <iostream>
#include <fstream>
#include <iomanip> //манипулатор ввода вывода

int main()
{
	std::ofstream ofile("D:\\stream.bin", std::ios::out | std::ios::binary);
	
	int a = 1232323278;
	double d = 2.1234093032;

	ofile.write(reinterpret_cast<char*>(&a), sizeof(a));
	ofile.write(reinterpret_cast<char*>(&d), sizeof(d));

	ofile.close();

	std::ifstream ifile("D:\\stream.bin", std::ios::in | std::ios::binary);

	int b = 0;
	double e = 0;

	ifile.read(reinterpret_cast<char*>(&b), sizeof(b));
	ifile.read(reinterpret_cast<char*>(&e), sizeof(e));

	std::cout << std::hex << std::setiosflags(std::ios::showbase) <<  b << std::endl;
	//std::hex манипулятор, который показывает в шестнадцатиричной системе 
	//для вывода 0x std::setiosflags(std::ios::showbase)
	std::cout << std::setprecision(12); //манипулятор, который принимает сколько
										//будет выводить знаков после запятой (iomanip)
	std::cout  << e << std::endl;

	return 0;
}*/
