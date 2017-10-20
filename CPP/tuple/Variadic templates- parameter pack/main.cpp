#include <iostream>
#include <string>
#include <tuple>
#include <cstdint>
#include <vector>
#include <algorithm>
#include "PrintTuple.h"

//Variadic templates
//std::tuple - кортеж
//parameter pack (не va_list) - упаковка параметров, можем работать только с шаблонами
//можем только передавать куда-нибудь
//можем только работать с одним параметром
//за исключение того, что вернуть функцией sizeof...
//(args)количество передаваемых параметров

template <class... Args>//для пустого принта
void print(Args... args)
{
	//std::cout << sizeof...(args) << std::endl;
}

template <class Head, class... Args>//перегрузка для принта с параметром
void print(Head head, Args... args)
{
	std::cout << head << std::endl;
	print(args...);//рекурсивно вызываем print
}

//или auto GetStudent() после 14 стандарта
std::tuple<int, std::string> GetStudent()//возвращаем несколько значений
{
	return std::make_tuple(20, "Vasya");
}

int main()
{
	print();
	print(1);
	print(1, 3, "C++");
	//print(1, args...);
	//print(3, args...);
	//print("C++", args...);
	//print(arts...);

	//создание кортежа
	std::tuple<int, std::string> t1{ 42, "C++" };//доступен только для чтения, и передачи
	std::tuple<int, std::string> t2(42, "C++");
	std::tuple<int, std::string> t3 = { 42, "C++" };
	std::tuple<int, std::string> t4 = std::make_tuple(42, "C++");
	std::tuple<> tx;
	auto t5 = std::make_tuple(42, "C++");

	//получить элемент из кортежа
	print(std::get<0>(t5));
	print(std::get<1>(t5));
	//print(std::get<2>(t5));
	//нельзя обратиться к несуществующим элементам(проверка на стадии компиляции)


	//std::tie Развязывание, распаковка
	int a;
	std::string b;
	auto t6 = std::tie(a, b) = std::make_tuple(33, "C++");//std::tie 2 и более lvalue ссылок, и возвращает кортеж
	print(a, b);

	//std::set s;
	//bool result;
	//std::tie(std::ignore, result) = s.insert(value);
	//std::ignore позволяет игнорировать распаковку параметра, а другое распаковывать

	int age;
	std::string name;
	std::tie(age, name) = GetStudent();

	print(age, name);

	//лямбда выражение
	auto getStudent2 = []() {
		return std::make_tuple(23, "Katya");
	};

	//сравнение кортежей
	if (std::make_tuple(42, "a") > std::make_tuple(41, "b"))
	{
		print("true");
	}

	struct Man
	{
		uint16_t age; //unsigned int 16 бит
		uint16_t languages;
		uint16_t jobs;
	};

	Man man1{ 23, 0, 3 };
	Man man2{ 24, 3, 1 };
	Man man3{ 20, 2, 0 };

	std::vector<Man> mans{ man1, man2, man3 };
	std::sort(mans.begin(), mans.end(), [](const Man& l, const Man& r)
	{ 
		return std::tie(l.jobs, l.languages, l.age) < std::tie(r.jobs, r.languages, r.age);
		//равносильно записи
		//return l.age < r.age;
		//return l.languages < r.languages;
		//return l.jobs < r.jobs;
	});

	std::for_each(mans.begin(), mans.end(), [](const Man& man)
	{
		std::cout << "jobs: " << man.jobs << " Langs: " << man.languages << " Age: " << man.age << std::endl;
	});

	auto superTuple = std::tuple_cat(std::make_tuple(1, 2, 3), std::make_tuple(4, 5, 6));
	//передаем компаратор(функция которая будет сравнивать два объекта)

	std::cout << superTuple << std::endl;	
}
