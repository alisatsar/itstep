#include <iostream>
#include "example.h"
#include <cstring>

String::String()
{
	strcpy(str, "");
}

String::String(char string[])
{
	strcpy(str, string);
}

void String::Display() const
{
	std::cout << str;
}

String String::operator+(String string) const
{
	String buff;

	if (strlen(str) + strlen(string.str) < SZ)
	{
		strcpy(buff.str, str);
		strcat(buff.str, string.str);
	}
	else
	{
		std::cout << "\nOverflow";
		exit(1);
	}
	return buff;
}
