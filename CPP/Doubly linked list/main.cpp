#include <iostream>
#include "list.h"

#include <list>
#include <algorithm>

int main()
{
	//int arr[5] = { 1, 3, 5, 2, 6 };

	//int* begin = arr;
	//int* end = arr + 5;

	//for (int* it = begin; it != end; it++)
	//{
	//	std::cout << *it << " ";
	//}
	List<int> list1;
	list1.insert(100, list1.end());
	list1.insert(101, list1.begin());
	List<int>::iterator it = list1.begin();
	list1.insert(102, ++it);
	for (List<int>::iterator it = list1.begin();
		it != list1.end(); ++it)
	{
		std::cout << *it << " ";
	}
	
	List<double> list2 = { 20.5, 2.01, 205.4, 208.3 };
	for (List<double>::iterator it = list2.begin(); it != list2.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::list<int> list3 = { 123, 23, 23, 454 };
	for (std::list<int>::iterator it = list3.begin(); it != list3.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::list<int>::iterator it1 =
		std::find(list3.begin(), list3.end(), 23);
	if (it1 != list3.end())
	{
		std::cout << "found " << *it1 << "\n";
	}
	std::cout << "count " << std::count(list3.begin(), list3.end(), 23);


	return 0;
}
