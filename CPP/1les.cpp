#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <tchar.h>

int main()
{
	/*wchar_t a;
	std::wstring str = L"abacaba"; //явным образом сигнализируем что это юникод (2 байта на символ)

	std::wcout << str;

	TCHAR* str1 = _TEXT("abacaba");*/

	char* strAnsi = "First lesson";

	size_t len = mbstowcs(NULL, strAnsi, 0) + 1;

	wchar_t* strUnicod = new wchar_t[len];

	int count = mbstowcs(strUnicod, strAnsi, len);
	
	std::wcout << strUnicod << std::endl;

	char* str = new char[len];

	count = wcstombs(str, strUnicod, len);

	std::cout << str << std::endl;
	
}
