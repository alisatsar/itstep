#include "Person.h"
#include <iostream>


int main()
{
	Person* personPtr[100];
	int n = 0;
	char choice;

	do
	{
		std::cout << "Student (s) or professor (p): ";
		std::cin >> choice;

		if (choice == 's')
		{
			personPtr[n] = new Student;
		}
		else
		{
			personPtr[n] = new Professor;
		}
		personPtr[n++]->GetData();
		std::cout << "You wanna add another person (y/n)? ";
		std::cin >> choice;
	} while (choice == 'y');

	for (int i = 0; i < n; i++)
	{
		personPtr[i]->PutName();
		if (personPtr[i]->IsOutStanding())
		{
			std::cout << "This is great person!\n";
		}
	}

	return 0;
}
