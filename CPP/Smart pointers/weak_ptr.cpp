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

	std::weak_ptr<Foo> foo;
};

struct Foo
{
	Foo()
	{
		std::cout << "Foo construct\n";
	}

	~Foo()
	{
		std::cout << "Foo destruct\n";
	}

	std::shared_ptr<Bar> bar;
};

int main()
{	
	//нельзя использовать shared_ptr при создании циклических указателей
	//не будет вызван деструктор
	//для этого используем weak_ptr
	{
		std::shared_ptr<Foo> foo = std::make_shared<Foo>();

		foo->bar = std::make_shared<Bar>();

		foo->bar->foo = foo;
	}	

	//Parent(shared_ptr) -> Node(weak_ptr)//parent Владеет Node, но Node не владеет Parent
	//Node -> Parent

	std::shared_ptr<Point> sp = std::make_shared<Point>();
	std::weak_ptr<Point> wp(sp);

	//std::cout << *wp << std::endl;//ошибка wp Нельзя разыменовать

	std::cout << *wp.lock << std::endl;

	std::cout << wp.expired() << std::endl;

	return 0;
}
