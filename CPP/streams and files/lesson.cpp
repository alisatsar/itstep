#include <iostream>
#include <fstream>
#include <iomanip> //манипулатор ввода вывода
#include <vector>

int main()
{
	double arr[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	std::ofstream ofile("D:\\stream.bin", std::ios::out | std::ios::binary);

	ofile.write(reinterpret_cast<char*>(&arr), sizeof(arr));

	ofile.close();

	std::ifstream ifile("D:\\stream.bin", std::ios::in | std::ios::binary);

	/*double arr1[10];

	ifile.read(reinterpret_cast<char*>(&arr1), sizeof(arr1));

	for (double el : arr1)
	{
		std::cout << el << std::endl;
	}*/

	std::vector<double> v;

	do
	{
		double buffer;
		ifile.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));

		if (ifile.gcount() == sizeof(buffer)) //возвращает количество байт сколько он считал перед этим
		{
			v.push_back(buffer);
		}
		
	} while (!ifile.eof());

	for (double el : v)
	{
		std::cout << el << " ";
	}

	return 0;
}

/*#include <iostream>
#include <fstream>
#include <iomanip> //манипулатор ввода вывода
#include <vector>


struct Complex
{
	float Im;
	float Re;
};

int main()
{
	Complex arr[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i].Im = i;
		arr[i].Re = i + 0.6;
	}

	std::ofstream ofile("D:\\stream.bin", std::ios::out | std::ios::binary);

	ofile.write(reinterpret_cast<char*>(&arr), sizeof(arr));

	ofile.close();

	std::ifstream ifile("D:\\stream.bin", std::ios::in | std::ios::binary);

	/*double arr1[10];

	ifile.read(reinterpret_cast<char*>(&arr1), sizeof(arr1));

	for (double el : arr1)
	{
		std::cout << el << std::endl;
	}*/

	std::vector<Complex> v;

	do
	{
		Complex buffer;
		ifile.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));

		if (ifile.gcount() == sizeof(buffer)) //возвращает количество байт сколько он считал перед этим
		{
			v.push_back(buffer);
		}
		
	} while (!ifile.eof());

	for (Complex el : v)
	{
		std::cout << el.Im << " " << el.Re << " ";
	}

	return 0;
}*/
