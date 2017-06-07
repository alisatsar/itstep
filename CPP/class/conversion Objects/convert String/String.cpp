#include <iostream>
#include "example.h"
#include <cstring>

String::String()
{
	str[0] = '\0';
}

String::String(char st[]) //конструктором с одним параметром
{
	strcpy(str, st);
}

void String::ShowStr()
{
	std::cout << str << std::endl;
}

////////////////////////////////////////////
String::operator char*()
{
	return str;
}
////////////////////////////////////////////
