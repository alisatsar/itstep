#include <iostream>
#include <vector>

int main()
{
	for (int i : { 1, 3, 5, 6, 7, }) //int i - объявление каждого элемента перебираемой коллекции coll
		// и к каждому элементу применяются указанные операторы
	{
		std::cout << i << std::endl;
	}

	std::vector<double> vec = { 1.1, 2.2, 4.4 };

	for (auto& elem : vec)//используется auto& elem, так как без ссылки for будет производить операции над копиями,
		//а не над самими объектами
	{
		elem *= 3;
		std::cout << elem << std::endl;
	}

	std::cout << vec[0];
}
