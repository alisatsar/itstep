#include "example.h"
#include <iostream>

int main()
{
	String s1 = "\nHappy New Year! ";
	String s2 = "Merry Cristmas!";
	String s3;

	s1.Display();
	s2.Display();
	s3.Display();

	s3 = s1 + s2;

	s3.Display();

	return 0;
}
