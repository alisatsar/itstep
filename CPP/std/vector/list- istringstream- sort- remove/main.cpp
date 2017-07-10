#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include "Student.h"
#include <list>

int main()
{
	// lesson_10_07_2017();

	std::vector<int> v = { 1, 3, 7, 4, 40, 23, 15, 9 };

	int min = 10;
	int max = 25;

	std::function<bool(int&)> lambda = [&min, &max](int& el) //&max не адрес, а ссылка
	{
		return el >= min && el <= max;
	};

	auto it = std::remove_if(v.begin(), v.end(), lambda); //remove_if принимает функцию
	v.erase(it, v.end());
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	// it = std::remove(v.begin(), v.end(),

	it = std::remove(v.begin(), v.end(), 3);
	v.erase(it, v.end());
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	min = 0;
	max = 10;

	std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), lambda);
	std::cout << std::endl;

	//sort <algorithm>

	std::vector<Student> students = { Student("Ivanov", 5), Student("Azarenko", 8),
		Student("Kozlov", 8), Student("Eroshenko", 3), Student("Belkin", 4), Student("Shukherman", 6) };

	std::sort(students.begin(), students.end());

	for (auto it = students.begin(); it != students.end(); ++it)
	{
		it->Print();
	}

	std::function<bool(Student const&, Student const&)> compareByRating =
		[](Student const& st1, Student const& st2)
	{
		return st1.GetRating() < st2.GetRating();
	};

	std::sort(students.begin(), students.end(), compareByRating);

	for (auto it = students.begin(); it != students.end(); ++it)
	{
		it->Print();
	}

	std::sort(students.begin(), students.end(), std::greater<Student>());

	for (auto it = students.begin(); it != students.end(); ++it)
	{
		it->Print();
	}

	std::list<int> list = { 2, 6, 4, 8, 25, 14, 4, 8 };

	std::list<int>::iterator startIt = list.begin();
	std::advance(startIt, 5); // пременим для всех контейнеров

	std::list<int>::iterator it1 = std::find(list.begin(), list.end(), 4);

	if (it1 != list.end())
	{
		std::cout << std::distance(list.begin(), it1) << std::endl;
		std::cout << *it1 << std::endl;
	}
	else
	{
		std::cout << "not found!\n";
	}

	list.push_front(5);
	list.push_front(10);

	std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;

	auto listLambda = [](int const& el)
	{
		return el >= 10;
	};

	list.remove_if(listLambda);

	list.sort();

	std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;

	//нельзя использовать std::sort для листа

	auto isGreater = [](int& el1, int& el2)
	{
		return el1 > el2;
	};

	list.sort(isGreater);

	list.unique(); //оставляет только уникальные элементы

	std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;

	
	auto remainerEquals = [](int& el1, int& el2)
	{
		return (el1 % 3) == (el2 % 3);
	};

	list.unique(remainerEquals);

	std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;

	std::istringstream is("10 23 5 7 8 4");
	std::vector<int> v3;
	//v3.resize(10);
	//std::copy(std::istream_iterator<int>(is),
		//std::istream_iterator<int>(),
		//v3.begin()); //начальный источник, конечный источник, назначение начало

	//std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));

	std::copy(std::istream_iterator<int>(is), std::istream_iterator<int>(), std::back_inserter(v3));

	std::copy(std::istream_iterator<int>(is), std::istream_iterator<int>(), std::front_inserter(list));

	std::copy(std::istream_iterator<int>(is), std::istream_iterator<int>(), std::inserter(v3, v3.begin() + 5));

	return 0;
}
