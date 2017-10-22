#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>

//std::auto_ptr
//std::shared_ptr
//std::unique_ptr
//std::weak_ptr

struct Point
{
	int x;
	int y;

	Point() : x(1), y(1)
	{
	}

	Point(int x, int y) : x(x), y(y)
	{
	}
};

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	return out << "x: " << point.x << " y: " << point.y << std::endl;
}

struct Foo;

struct Bar
{
	Bar()
	{
		std::cout << "Bar construct\n";
	}

	~Bar()
	{
		std::cout << "Bar destruct\n";
	}

	std::shared_ptr<Foo> foo;
};

struct Foo
{
	Foo()
	{
		std::cout << "Bar construct\n";
	}

	~Foo()
	{
		std::cout << "Bar destruct\n";
	}

	std::shared_ptr<Bar> bar;
};

int main()
{
	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 5);//появился в 11 стандарте
	std::shared_ptr<Point> sp2 = sp1;

	std::cout << *sp1 << std::endl;
	std::cout << *sp2 << std::endl;

	std::cout << sp1.use_count() << std::endl;//Возвращает количество ссылок

	auto testUseCout = [](const auto& value)//вывод будет 2, так как передаем значение по ссылке
	{
		std::cout << value.use_count() << std::endl;
	};

	testUseCout(sp2);

	auto testUseCout2 = [](auto value)//вывод будет 3, так как происходит копирование
	{
		std::cout << value.use_count() << std::endl;
	};

	testUseCout2(sp2);

	//auto spArray = std::make_shared<Point[]>();//ошибка
	//нет delete[]
	
	//нельзя использовать shared_ptr при создании циклических указателей
	//не будет вызван деструктор
	//для этого используем weak_ptr
	{
		std::shared_ptr<Foo> foo = std::make_shared<Foo>();

		foo->bar = std::make_shared<Bar>();

		foo->bar->foo = foo;
	}	

	return 0;
}
