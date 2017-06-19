#include <iostream>
#include "list.h"

int main()
{
	//int arr[5] = { 1, 3, 5, 2, 6 };

	//int* begin = arr;
	//int* end = arr + 5;

	//for (int* it = begin; it != end; it++)
	//{
	//	std::cout << *it << " ";
	//}

	List list;
	list.Insert(100, list.end());
	list.Insert(101, list.begin());
	Iterator it = list.begin();
	list.Insert(102, ++it);
	for (Iterator it = list.begin();
		it != list.end(); ++it)
	{
		std::cout << *it << " ";
	}

	List list2 = { 1, 3, 5, 6 };

	return 0;
}
