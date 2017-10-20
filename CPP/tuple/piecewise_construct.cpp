#include <iostream>
#include <utility>// pair
#include <tuple>

class Foo
{
public:
	Foo(std::tuple<int, float>)
	{
		std::cout << "Foo::Foo(tuple)" << std::endl;
	}

	template<class... Args>
	Foo(Args... args)
	{
		std::cout << "Foo::Foo(args...)" << std::endl;
	}
};

int main()
{
	//создаем кортеж t:
	std::tuple<int, float> t(1, 3.33);
	
	//передаем конструктору Foo кортеж как единое целое:
	std::pair<int, Foo> p(0, t);

	//передаем конструктору Foo элементы кортежа:
	std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(42), t);
	//параметр std::piecewise_construct, переданный как первый аргумент, 
	//вынужденно использует конструктор кортежа не как единый кортеж(int, float)
}
