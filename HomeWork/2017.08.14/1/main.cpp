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

	char strAnsi[256];

	wchar_t* strUnicode;

	size_t len;


	//getline
	/*while (ifile.getline(strAnsi, 256))
	{
		len = mbstowcs(NULL, strAnsi, 0) + 1;

		strUnicode = new wchar_t[len];

		mbstowcs(strUnicode, strAnsi, len);

		ofile << strUnicode << std::endl;
	}*/


	//read
	/*char* text = new char[2500];
	memset(text, 0, 2500);
	ifile.read(text, 2500);
	len = mbstowcs(NULL, text, 0) + 1;
	strUnicode = new wchar_t[len];
	mbstowcs(strUnicode, text, len);
	ofile << strUnicode << std::endl;*/


	//get
	char c[2500];

	while (!ifile.eof())
	{
		ifile.get(c, 2500, '\0');

		len = mbstowcs(NULL, c, 0) + 1;

		strUnicode = new wchar_t[len];

		mbstowcs(strUnicode, c, len);

		ofile << strUnicode << std::endl;
	}

	ofile.close();
	ifile.close();
}
