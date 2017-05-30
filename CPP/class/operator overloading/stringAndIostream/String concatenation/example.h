#pragma once

class String
{
private:
	enum {SZ = 80 };
	char str[SZ];
		
public:
	String();
	String(char string[]);

	void Display() const;
	String operator+(String string) const;
};
