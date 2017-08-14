#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
	setlocale(LC_ALL, "russian");

	std::string buffer;

	std::ifstream ifile("C:\\Users\\st\\Desktop\\lopatin.txt");

	if (!ifile.is_open())
	{
		return 0;
	}

	int length;

	std::cout << "Enter the length of string: ";
	std::cin >> length;
	
	std::ofstream ofile("C:\\Users\\st\\Desktop\\result.txt", std::ios::trunc);

	int count = 0;

	std::unordered_set<char> glas{ 'е', 'о', 'э', 'я', 'и', 'у', 'ю', 'ы', 'а' };

	while (std::getline(ifile, buffer)) 
	{
		if ((buffer.length() == length))
		{
			for (auto symb : buffer)
			{
				if (glas.find(symb) != glas.end())
				{
					++count;
				}
			}
			if (count == 2)
			{
				ofile << buffer << std::endl;
			}
			count = 0;
		}
	}

	ifile.close();
	ofile.close();
}
