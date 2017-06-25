#pragma once
#include <iostream>

class Person
{
protected:
	char name[40];
public:
	void GetName()
	{
		std::cout << " Enter name: ";
		std::cin >> name;
	}

	void PutName()
	{
		std::cout << "  Name: " << name << std::endl;
	}
	virtual void GetData() = 0;
	virtual bool IsOutStanding() = 0;
};

class Student : public Person
{
private:
	float gpa;
public:
	void GetData()
	{
		Person::GetName();
		std::cout << "	 The average student score: ";
		std::cin >> gpa;
	}

	bool IsOutStanding()
	{
		return (gpa > 3.5) ? true : false;
	}
};

class Professor : public Person
{
private:
	int numPubs;
public:
	void GetData()
	{
		Person::GetName();
		std::cout << "    The quantity of publications: ";
		std::cin >> numPubs;
	}

	bool IsOutStanding()
	{
		return (numPubs > 100) ? true : false;
	}
};
