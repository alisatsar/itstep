#include <iostream>

template <class T>
class A;

template<>
class A<int>
{
public:
	typedef int Ac;
};

template<>
class A<float>
{
public:
	typedef float Ac;
};

template<class T>
T average(T& a, T& b)
{
	return A<T>::Ac(a + b) / 2;
}

template<class T>
class Point
{
	T m_x;
	T m_y;
public:

	Point(T const& x = 0, T const& y = 0) :m_x(x), m_y(y)
	{
	}
	void Show() const;
};

template<class T>
void Point<T>::Show() const
{
	std::cout << m_x << m_y << std::endl;
}

int main()
{
	Point<double> p1(1.2, 3.4);
	p1.Show();

	Point<double> p2(3.4);
	p2.Show();

	int a = 3;
	int b = 5;

	std::cout << average(a, b);

	return 0;
}
