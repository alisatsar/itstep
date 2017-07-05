#include <fstream>
#include <iostream>

class Person
{
protected:
	char name[50];
	short age;
public:
	void GetData()
	{
		std::cout << "Name: ";
		std::cin >> name;
		std::cout << "Age: ";
		std::cin >> age;
	}

	void ShowData()
	{
		std::cout << "\n Name: " << name;
		std::cout << "\n Age: " << age;
	}
};

int main()
{
	char ch;
	Person p1;
	std::fstream file;		//создать входной/выходной файл

	file.open("Person.bin", std::ios::app | std::ios::out | std::ios::in | std::ios::binary);

	do
	{
		std::cout << "\nEnter the data of person: ";
		p1.GetData();

		file.write(reinterpret_cast<char*>(&p1), sizeof(p1));

		std::cout << "Continue (y/n)?";
		std::cin >> ch;

	} while (ch == 'y');

	file.seekg(0);	//поставить указатель на начало файла

	file.read(reinterpret_cast<char*>(&p1), sizeof(p1));

	while (!file.eof())
	{
		std::cout << "\nPerson: ";
		p1.ShowData();
		file.read(reinterpret_cast<char*>(&p1), sizeof(p1));
	}
}
