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

//функтор - объекты у которых перегружен оператор вызова
struct Deleter
{
	Deleter() {};
	~Deleter() {};

	void PrintBar()
	{
		std::cout << "bar";
	}

	void operator()(Point* p)
	{
		delete[] p;
	}
};

int main()
{
	std::unique_ptr<Point> up1 = std::unique_ptr<Point>(new Point(1, 2));
	//std::unique_ptr<Point> up2 = up1;//копирующий конструктор удален, ошибка
	std::unique_ptr<Point> up2 = std::move(up1);//перемещаем up1 в up2;
	
	std::cout << *up2;

	if (up1)//перегруженный operator bool()
	{
		std::cout << *up1;
	}

	std::unique_ptr<Point> up3(new Point);
	auto up4 = std::unique_ptr<Point>(new Point);
	
	std::unique_ptr<Point> up5 = std::make_unique<Point>();//вариадик функция, можем передавать много разный аргумнетов
	std::unique_ptr<Point> up6 = std::make_unique<Point>(3, 3);//констуктор Point(x, y) находится в (3, 3);
	auto up7 = std::make_unique<Point>(4, 5);

	std::cout << *up7 << std::endl;

	//создание указателя на массив
	auto upArray = std::make_unique<Point[]>(6);//создаем массив 6 элементов
	//operator delete[]
	auto up8 = std::make_unique<Point>(6, 6);
	//operator delete

	for (int i = 0; i < 6; i++)
	{
		upArray[i].x = i;
		upArray[i].y = i;
	}

	//для того, чтобы вызвался правильный конструктор для удаления массива
	//на который указывает std::unique_ptr
	//позволено создавть свой кастомный delete

	std::unique_ptr<Point, Deleter> up9(new Point[10], Deleter());
	std::cout << up9.get()[9];

	std::unique_ptr<Point, std::function<void(Point*)>> up10(new Point[3], [](auto* p) {delete[] p; });

	std::unique_ptr<Point, Deleter> up11(new Point[10], Deleter());
	auto myDeleter = up11.get_deleter();
	
	up2.swap(up3);//меняем указатели местами

	up11.reset(new Point);//перегрузится новым указателем
	up11.reset();//nullptr делает
	return 0;
}
