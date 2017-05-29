#pragma once

class String
{
private: 
	char* m_str = nullptr;    //тот же NULL только его нельзя привести к инту
public:
	String();
	String(char const* str);		//конструктор с параметрами
	String(String const& string);		//конструктор копирования
	~String();							//деструктор

	char const* GetCString() const;
	size_t findLength() const;
	void PrintString();
	String operator+(String const& str);

	bool operator==(String const& str);
	bool operator!=(String const& str);
	bool operator<(String const& str);
	bool operator>(String const& str);
	friend std::istream& operator >> (std::istream& stream, String& string);
};

std::ostream& operator << (std::ostream& stream, String const& string);
std::istream& operator >> (std::istream& stream, String& string);
