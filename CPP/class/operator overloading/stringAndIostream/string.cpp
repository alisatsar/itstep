#include <iostream>
#include "String.h"
#include <cstring>
#include <iosfwd>

String::String()
{
	m_str = new char[1];
	std::memset(m_str, 0, 1);
}

String::String(char const* str)
{
	size_t length = strlen(str);		//size_t возвращает unsigned int
	m_str = new char[length + 1];
	//strcpy(m_str, str);
	memcpy(m_str, str, length + 1);
}

String::String(String const& string)
{
	size_t length = strlen(string.m_str);		//size_t возвращает unsigned int
	m_str = new char[length + 1];
	strcpy(m_str, string.m_str);
}

String::~String()
{
	delete[] m_str;
}

size_t String::findLength() const
{
	size_t length = strlen(m_str);
	return length;
}

char const* String::GetCString() const
{
	return m_str;
}

void String::PrintString()
{
	std::cout << m_str << std::endl;
}

String String::operator+(String const& str)
{
	int length = findLength() + str.findLength();
	String buff;
	delete[] buff.m_str;
	buff.m_str = new char[length + 1];
	strcat(buff.m_str, m_str);
	strcat(buff.m_str, str.m_str);

	return buff;
}

bool String::operator==(String const& str)
{
	return strcmp(m_str, str.m_str) == 0;
}

bool String::operator!=(String const& str)
{
	return !(*this == str);
	//return strcmp(m_str, str.m_str) != 0;
}

bool String::operator<(String const& str)
{
	return strcmp(m_str, str.m_str) == -1;
}

bool String::operator>(String const& str)
{
	return strcmp(m_str, str.m_str) == 1;
}

std::ostream& operator << (std::ostream& stream, String& string)
{
	stream << string.GetCString() << "\'";
	return stream;
}

std::istream& operator >> (std::istream& stream, String& string)
{
	char buff[1024];
	stream.getline(buff, 1024);
	size_t length = strlen(buff);
	delete[] string.m_str;
	string.m_str = new char[length + 1];
	strcpy(string.m_str, buff);

	return stream;
}
