#pragma once
#include <iostream>

const int LEN = 80;

class Employee
{
private:
	char name[LEN];
	unsigned long number = 0;
public:
	void GetData()
	{
		std::cout << "\nEnter name: ";
		std::cin >> name;
		std::cout << "\nEnter number: ";
		std::cin >> number;
	}

	void PutData() const
	{
		std::cout << "\nName: " << name;
		std::cout << "\nNumber: " << number;
	}
};

class Manager : public Employee
{
private:
	char title[LEN];
	double dues = 0;
public:
	void GetData()
	{
		Employee::GetData();
		std::cout << " Enter the post: ";
		std::cin >> title;
		std::cout << " Enter summ: ";
		std::cin >> dues;
	}

	void PutData() const
	{
		Employee::PutData();
		std::cout << "\nThe post: " << title;
		std::cout << "\nThe summ: " << dues;
	}
};

class Scientist : public Employee
{
private:
	int pubs = 0;
public:
	void GetData()
	{
		Employee::GetData();
		std::cout << "Enter quantity of publication: ";
		std::cin >> pubs;
	}

	void PutData() const
	{
		Employee::PutData();
		std::cout << "\n The quantity of publications: " << pubs;
	}
};

class Laborer : public Employee
{
};
