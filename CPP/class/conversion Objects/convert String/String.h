#pragma once
#include <iosfwd>

class String
{
private:
	enum {SZ = 80};
	char str[SZ];

public:
	String();
	String(char st[]); //конструктором с одним параметром
	void ShowStr();
  
  //////////////////////////////////////////////////
	operator char*();  //перевод строкик обычному типу
  //////////////////////////////////////////////////
  
};
