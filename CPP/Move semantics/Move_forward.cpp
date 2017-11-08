#include <iostream>]
#include <type_traits>


struct A
{
	A()
	{
		std::cout << "A default constructor." << std::endl;
	}

	A(const int& i)
	{
		std::cout << i << std::endl;
	}

	void foo(const int& i)
	{
		std::cout << "this is lvalue\n";
	}

	//двойна ссылка, rvalue ссылка
	void foo(int&& i)
	{
		std::cout << "this is rvalue\n";
	}
	
	template <class T>
	void fooT(T&& i)
	{
		if (std::is_rvalue_reference<T>::value) std::cout << "Rvalue\n";
		if (std::is_lvalue_reference<T>::value) std::cout << "Lvalue\n";
		if (!std::is_reference<T>::value) std::cout << "Non reference\n";
	}
};

struct B
{
	B(A a)
	{
	}
};

struct C
{
	void inc(int& a)
	{
		a++;
	}
};

int foo()//RVO return value optimization
{
	return 42;//возвращаются напрямую, не создавая копий
}

int&& MyMoveInt(int& i)
{
	return static_cast<int&&>(i);
}

template <class T>//если передать lvalue, то вернет T&, так как 
//T&& + T& = T&(сжатие ссылок)
T&& moveT(T&& t)
{
	return static_cast<T&&>(t);
}

template <class T>
struct My_remove_reference
{
	typedef T value;
};

template <class T>
struct My_remove_reference<T&>
{
	typedef T value;
};

template <class T>
struct My_remove_reference<T&&>
{
	typedef T value;
};

template <class T>
constexpr typename My_remove_reference<T>::value&&
moveReal(T&& t) noexcept
{
	return static_cast<typename My_remove_reference<T>::value&&>(t);
}

class Data
{
public:
	Data() {};
	Data(const Data& data) {};
	Data(Data&& data) {};
};

//std::forvard функция, которая восстанавливает тип ссылки


//пишем свой forvard
//A& A&, A -> A&&
//для примера
//int&& forward_int(int& i)
//{
//	return static_cast<int&&>(i);
//}

template <class T>
T&& forwardT(T& t)
{
	return static_cast<T&&>(t);
}

template <class T>
constexpr T&& forwardReal(typename My_remove_reference<T>::value& t) noexcept
{
	return static_cast<T&&>(t);
}

template <class T, class Args>
T* make_ptr(Args&& arg)
{
	return new T(forwardReal<Args>(arg));
}


int main()
{	
	A a{};
	int i3 = 3;
	a.foo(i3);//принимает lvalue
	a.foo(std::move(i3));//принимает rvalue
	//std::move - Конвектор, который превращает rvalue
	//на самом деле std::move Делает xvalue

	int i = 11;
	static_cast<int&&>(i);//преобразование lvalue в rvalue

	a.foo(static_cast<int&&>(i));//конструктор принимает rvalue
	a.foo(static_cast<int&>(i));//преобразования нет, просто явно указываем тип lvalue

	int i12 = 12;
	a.foo(moveReal(i12));

	Data d;
	Data* d2 = make_ptr<Data>(d);//копирование
	Data* d3 = make_ptr<Data>(Data());//перемещение
	delete d2;
	delete d3;

	return 0;
}
