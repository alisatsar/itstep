/*Задание 2
Дан текстовый файл karatkevich.txt в кодировке UTF - 8.
Найдите длину : самого длинного слова, а также все такие слова и их количество;
самого короткого слова, а также все такие слова и их количество;
среднюю длину слова.Выведите полученную информацию в файл в кодировке UTF - 8.*/

#include <fstream>
#include <iostream>
#include <string>
#include <codecvt> 
#include <vector>

int main()
{
	std::wifstream ifile("C:\\Users\\gamer\\Desktop\\karatkevich.txt");

	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>); 

	ifile.imbue(loc);

	if (!ifile.is_open())
	{
		return 0;
	}

	int maxChar = 0;
	int minChar = 1;

	std::wstring buffer;

	std::vector<std::wstring> maxWords;
	std::vector<std::wstring> minWords;

	long summAllWords = 0;
	long allLen = 0;

	size_t len;

	while (ifile >> buffer)
	{
		len = buffer.length();
		allLen += len;
		if (len > maxChar)
		{
			maxChar = len;
			maxWords.clear();
		}

		if (len == maxChar)
		{
			maxWords.push_back(buffer);
		}
		
		if (len == minChar)
		{
			minWords.push_back(buffer);
		}
		++summAllWords;
	}

	std::wofstream ofile("C:\\Users\\gamer\\Desktop\\maxWords.txt");

	ofile.imbue(loc);

	ofile << L"Длина среднего слова: " << std::to_wstring(allLen / summAllWords) << std::endl;

	ofile << L"Длина самого длинного слова: " << std::to_wstring(maxChar) << std::endl;
	
	for (auto& elem : maxWords)
	{
		ofile << elem << std::endl;
	}

	ofile << L"Количество слов: " << std::to_wstring(maxWords.size()) << std::endl;
	
	ofile << L"Длина самого маленького слова: " << std::to_wstring(minChar) << std::endl;

	for (auto& elem : minWords)
	{
		ofile << elem << std::endl;
	}

	ofile << L"Количество слов: " << std::to_wstring(minWords.size()) << std::endl;
	
	ofile.close();
	ifile.close();
}
