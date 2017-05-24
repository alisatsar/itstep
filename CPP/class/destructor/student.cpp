#include "student.h"

#include <cstring>
#include <iostream>

Student::Student(Group& group) :
	m_group(group),
	m_rating(0)
{
	m_name = new char[1];
	m_name[0] = '\0';
}

Student::Student(Group& group, char const* name, int rating) :
	m_name(NULL),
	m_group(group),
	m_rating(rating)
{
	SetName(name);
}

Student::Student(Student const& student) :
	m_group(student.m_group),
	m_rating(student.m_rating)
{
	std::cout << "copy constructor\n";
	SetName(student.GetName());
}

Student::~Student()
{
	delete[] m_name;
}

char const* Student::GetName() const
{
	return m_name;
}

int Student::GetRating() const
{
	return m_rating;
}

void Student::SetName(char const* name)
{
	delete[] m_name;
	size_t length = strlen(name);
	m_name = new char[length + 1];
	strcpy(m_name, name);
}

void Student::SetRating(int rating)
{
	m_rating = rating;
}

void Student::Read()
{
	std::cout << "Enter name: ";
	char buffer[21];
	std::cin.getline(buffer, 20);
	SetName(buffer);
	std::cout << "Enter rating: ";
	std::cin >> m_rating;
}

void Student::Print() const
{
	std::cout << m_name << ": " << m_rating << "\n";
}
