#include <iostream>
#include <memory>
#include <vector>

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

int main()
{
	std::auto_ptr<Point> p1 = std::auto_ptr<Point>(new Point);//создаем умный указатель на точку
	//далее нам не надо будет освобождать память под точку
	//создан только один указатель на один объект
	std::auto_ptr<Point> p2 = p1;//p1 перемещается в p2, p1 становится пустым

	//std::cout << *p1; ошибка, так как указатель пустой

	std::vector<std::auto_ptr<Point>> vec;
	vec.push_back(std::auto_ptr<Point>(new Point(2, 2)));
	vec.push_back(std::auto_ptr<Point>(new Point(3, 3)));	

	auto elem = vec[0];//происходит перемещение, vec[0] теперь пустой
	//std::cout << *vec[0]; ошибка
	//std::auto уберут в 17 стандарте

	//инициализация
	auto p3 = std::auto_ptr<Point>(new Point);
	auto p4 = std::auto_ptr<Point>{ new Point{5, 5} };

	std::cout << vec[1].get();//метод get возвращает голый указатель

	return 0;
}
