#include <sstream>
#include <string>
#include <iostream>
#include <exception>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

class CalcException : public std::exception
{
public:
	char const* what() const override
	{
		return "invalid argument\n";
	}
};

double CalculateSqrt(double value)
{
	if (value < 0)
	{
		throw CalcException();
	}
	return sqrt(value);
}

void Sort(int* array, int count)
{

}

int main()
{
	/*std::string str = "Type:Studeng name:Ivanov rating:8";
	std::istringstream is(str);

	std::string buf;
	while (!is.eof())
	{
		is >> buf; // читаем из потока до пробела Type:Studeng
		std::istringstream is2(buf); // создаем стрим с Type:Studeng
		char part[1024];
		is2.getline(part, 1024, ':'); // считывает до :
		std::cout << "key=" << part;
		is2.getline(part, 1024, ':'); //так как не находит еще одно :, то считывает остаток строки
		std::cout << ", value=" << part << std::endl;
	}

	double v = -3;
	try
	{
		double value = CalculateSqrt(v);
		std::cout << value << std::endl;
	}
	catch (std::exception& ex) //  (CalcException& ex)
	{
		std::ostringstream os;
		os << "error in function CalcSqrt()" << ",argument: " << v << ", :" << ex.what();
		std::cout << os.str() << std::endl;
	}
	
	std::ostringstream os1;
	os1 << 5 << " + " << 6 << " = " << (5 + 6);

	std::cout << os1.str() << std::endl; // метод который возвращает то, что в нем накопилось(буффер)

	std::istringstream is1("123");
	int a;
	is1 >> a; // преобразования числа в строку, запись в переменную a
	std::cout << a + 1 << std::endl;*/

	std::vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//передаем контейнер начала и конца, и начала куда вставляем 
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

	std::vector<int> v1 = { 1, 19, 20 };
	std::vector<int> v2(20, 100);
	std::vector<int> v3(std::move(v1));

	std::vector<int> v4(v.begin(), v.begin() + 5);

	std::copy(v4.begin(), v4.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;
	
	std::cout << v4.front() << " " << v4.back() << std::endl;

	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;

	v3.reserve(20);		//сколько выделено capacity	
	v3.resize(15);		//size = 15, заполняет нулями

	std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));

	std::vector<int>::reverse_iterator it = v3.rbegin();
	
	for (; it != v3.rend(); ++it)
	{
		std::cout << *it << " ";
	}

	std::copy(v2.rbegin(), v2.rend(), std::ostream_iterator<int>(std::cout, " "));

	int* array = &v3[0];
	int* array1 = &v3.front();
	int* array2 = v3.data(); //возвращает указатель на начало вектора

	Sort(v3.data(), v3.size());

	v3.insert(v3.begin() + 1, 100);
	std::copy(v3.begin(), v3.end(),	std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	v3.insert(v3.begin() + 5, 5, 500); //вставить 5 раз 500
	std::copy(v3.begin(), v3.end(),	std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	std::vector<int>::iterator it1 = v3.insert(v3.begin() + 5, 100);

	std::cout << std::distance(v3.begin(), it1)	<< std::endl; 
	//std::distance алгоритм возращает расстояние между итераторами v3.begin() и it1

	it1 = v3.erase(it1);
	std::copy(v3.begin(), v3.end(),	std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	v3.erase(it1, it1 + 5);
	std::copy(v3.begin(), v3.end(),	std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	for (std::vector<int>::iterator i = v3.begin(); i != v3.end();)
	{
		if ((*i % 2) == 0)
		{
			i = v3.erase(i);
		}
		else
		{
			++i;
		}
	}

	std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	v3.insert(v3.begin(), 0);
	v3.insert(v3.begin() + 2, 0);
	v3.resize(10);
	v3.insert(v3.begin() + 2, 5, 100);

	std::copy(v3.begin(), v3.end(),	std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	/*auto it4 = std::remove(v3.begin(), v3.end(), 0); // тип, который выводится справа от оператора =

	std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	auto b = 10 / 3; //auto будет типа Int так как 10 int и 3 int

	std::cout << std::distance(v3.begin(), it4)	<< std::endl;

	v3.erase(it4, v3.end());*/

	v3.erase(std::remove(v3.begin(), v3.end(), 0), v3.end());
	std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::vector<int> v5;
	v5.reserve(100);
	v5.insert(v5.begin(), { 1, 3, 65, 7 });

	std::cout << v5.size() << " " << v5.capacity() << std::endl;
	v5.shrink_to_fit();
	std::cout << v5.size() << " " << v5.capacity() << std::endl;

	for (std::size_t i = 0; i < v5.size(); i++)
	{
		std::cout << v5[i] << " ";
	}

	//typeid(); возвращает тип auto

	std::vector<int> v6 = { 1, 2, 7, 34, 7, 3, 40 };
	std::copy(v6.begin(), v6.end(),	std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	auto lambda = [](int& el)
	{
		return (el % 2) == 0;
	};

	auto it5 = std::remove_if(v6.begin(), v6.end(), lambda);
	v6.erase(it5, v6.end());
	std::copy(v6.begin(), v6.end(),	std::ostream_iterator<int>(std::cout, " "));
	
	return 0;
}
