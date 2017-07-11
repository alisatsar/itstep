// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
#include <deque>
#include "Student.h"

int Summ(int a, int b, int c)
{
	return a + b + c;
}

bool less(int a, int b)
{
	return a < b;
}

int main()
{
	std::deque<Student> d;
	d.push_front(Student("Ivanov", 7));
	d.push_front(Student("Azarenko", 5));
	d.push_front(Student("Petrov", 3));

	auto printStudent = [](Student const& st)
	{
		st.Print();
	};

	std::for_each(d.begin(), d.end(), printStudent);

	std::for_each(d.begin(), d.end(), std::bind(&Student::Print, std::placeholders::_1));

	std::function<int(int, int, int)> summ3 = Summ;

	int a = summ3(1, 3, 5);

	std::function<int(int, int)> summ2 =
		std::bind(summ3, std::placeholders::_1,
			std::placeholders::_2, 0); //_1 позиция

	a = summ2(1, 2);

	std::function<int(int, int)> Greater =
		std::bind(less, std::placeholders::_2,
			std::placeholders::_1); //_1 позиция

	std::sort(d.begin(), d.end(), std::less<Student>());
	std::for_each(d.begin(), d.end(), std::bind(&Student::Print, std::placeholders::_1));
	std::cout << std::endl;


	std::sort(d.begin(), d.end(), std::bind(std::less<Student>(), std::placeholders::_2, std::placeholders::_1));

	std::for_each(d.begin(), d.end(), std::bind(&Student::Print, std::placeholders::_1));
	std::cout << std::endl;

	std::vector<int> v = { 1, 10, 15, 20, 21, 3 };

	std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "),
		std::bind(std::logical_and<bool>(),
			std::bind(std::greater<int>(), std::placeholders::_1, 10),
			std::bind(std::less<int>(), std::placeholders::_1, 20)));

	std::deque<std::string> names = { "Kozlov", "Eroshenko", "Shukherman" };

	std::vector<Student> students;

	int rating = 6;

	std::function<Student(std::string const&)> createStudent = [&rating](std::string const& name)
	{
		return Student(name, rating);
	};

	std::transform(names.begin(), names.end(), std::back_inserter(students), createStudent);

	std::for_each(students.begin(), students.end(), std::bind(&Student::Print, std::placeholders::_1));
	std::cout << std::endl;

	return 0;
}
