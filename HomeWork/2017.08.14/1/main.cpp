/*Задание 1
Дан файл text.txt, в котором есть текст в кодировке ANSI.
Запишите этот же текст в файл с кодировкой UTF - 8.
При работе вам понадобится : подключить <codecvt>
использовать поток wofstream
дописать две строчки :
std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
fout.imbue(loc);
*Реализуйте чтение из файла разными способами, например:
с помощью метода getline;
с помощью метода read;
с помощью метода get.*/

#include <fstream>
#include <string>
#include <locale.h>
#include <codecvt>
#include <iostream>
#include <vector>

int main()
{
	setlocale(LC_ALL, "russian");
	std::ifstream ifile("C:\\Users\\gamer\\Desktop\\text.txt", std::ios_base::end);

	if (!ifile.is_open())
	{
		exit(1);
	}

	std::wofstream ofile("C:\\Users\\gamer\\Desktop\\result.txt");

	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);

	ofile.imbue(loc);

	char strAnsi[250];

	std::string buffer;

	wchar_t* strUnicode;

	size_t len;
//	ifile.getline(strAnsi, 256)

	/*while (std::getline(ifile, buffer))
	{
	strcpy(strAnsi, buffer.c_str());
	len = mbstowcs(NULL, strAnsi, 0) + 1;
	strUnicode = new wchar_t[len];
	mbstowcs(strUnicode, strAnsi, len);
	ofile << strUnicode << std::endl;
	}*/

	auto size = ifile.tellg();

	ifile.seekg(0);

	char* text = new char[size];

	ifile.read(text, size);

	len = mbstowcs(NULL, text, 0) + 1;

	strUnicode = new wchar_t[len];

	mbstowcs(strUnicode, text, len);

	ofile << strUnicode << std::endl;
}
