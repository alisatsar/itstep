#include "String.h"
#include "Student.h"
#include <memory>
#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Array.h"

template<class T> //объявление общего классы
class AccumulationTraits;


////специлазации класса AccumulationTraits
template<>
class AccumulationTraits<int>
{
public:
	typedef int AccT;
};

template<>//указывает что это шаблон
class AccumulationTraits<char>
{
public:
	typedef int AccT;
};

template<>
class AccumulationTraits<double>
{
public:
	typedef double AccT;
};

template<>
class AccumulationTraits<float>
{
public:
	typedef double AccT;
};

char const* max(char const* a, char const* b)
{
	return strcmp(a, b) > 0 ? a : b;
}

template<class T>
double average(T* array, int count)
{
	AccumulationTraits<T>::AccT summ = 0;
	for (int i = 0; i < count; i++)
	{
		summ += array[i];
	}
	return summ / count;
}

template <class T>
class Compare
{
	T m_value;
public:
	Compare() = default;
	Compare(T value) : m_value(value)
	{
	};

	bool operator()(T const& value)
	{
		return m_value == value;
	}
};

template <class T>
class Greater
{
	T m_value;
public:
	Greater() = default;
	Greater(T value) :m_value(value)
	{
	}

	bool operator()(T const& value)
	{
		return m_value < value;
	}
};

typedef bool(*CompareFunc)(int const&);

bool CompareWith5(int const& value)
{
	return value == 5;
}

bool GreaterThan5(int const& value)
{
	return value > 5;
}

/*int* Find(int* array, int count, CompareFunc compare)
{
	for (int i = 0; i < count; i++)
	{
		if ((*compare)(array[i]))
		{
			return array + i;
		}
	}
	return nullptr;
}*/

/*int* Find(int* array, int count, Compare compare)
{
	for (int i = 0; i < count; i++)
	{
		if (compare(array[i]))
		{
			return array + i;
		}
	}
	return nullptr;
}*/

template<class T, class Pred>
T* find(T* array, int count, Pred compare)
{
	for (int i = 0; i < count; i++)
	{
		if (compare(array[i]))
		{
			return array + i;
		}
	}
	return nullptr;
}

template<class T>
T const& max(T const& a, T const& b)
{
	return a > b ? a : b;
}

template<class T>
T const& max(T const& a, T const& b, T const& c)
{
	return max(max(a, b), c);
}

template<class T>
T const& min(T const& a, T const& b)
{
	return a < b ? a : b;
}

template<class T1, class T2>
bool IsGreater(T1 const& a, T2 const& b)
{
	return a > (T1)b;
}

bool IsGreater(int const& a, double const& b)
{
	return (double)a > b;
}

template <class T>
class GreaterFromTwo
{
public:
	GreaterFromTwo() = default;
	GreaterFromTwo(T value) :m_value(value)
	{
	}

	bool operator()(T const& value, T const& value2)
	{
		return value > value2;
	}
};

class GreaterFromTwoStudentByRating
{
public:
	GreaterFromTwoStudentByRating() = default;

	bool operator()(Student const& value1,
		Student const& value2) const
	{
		return value1.GetRating() > value2.GetRating();
	}
};

/*template<>
class GreaterFromTwo<Student>
{
public:
	GreaterFromTwo() = default;

	bool operator()(Student const& value1,
		Student const& value2) const
	{
		return value1.GetRating() > value2.GetRating();
	}
};*/

template<class T, class Pred = GreaterFromTwo<T>>
void BubbleSort(T* array, int count, Pred compare = GreaterFromTwo<T>())
{
	for (int i = count - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (compare(array[j], array[j + 1]))
			{
				T buff = std::move(array[j]);
				array[j] = std::move(array[j + 1]);
				array[j + 1] = std::move(buff);
			}
		}
	}
}

void plus(int& a, int b = 5, double c = 3.4)//АРгументы по умолчанию должны быть в конце
{
	a += b;
}

int main()
{
	//через указатель на функцию
	/*int a = 5;
	int b = 4;
	Compare cmp(5);

	CompareFunc cmp1 = CompareWith5;

	if (cmp(a))
	{
		std::cout << "true\n";
	}
	else
	{
		std::cout << "false\n";
	}

	if ((*cmp1)(b))
	{
		std::cout << "true\n";
	}
	else
	{
		std::cout << "false\n";
	}

	int arr[] = { 1, 10, 5, 6, 7 };
	int* result = Find(arr, 5, GreaterThan5);
	if (result)
	{
		std::cout << *result << "\n";
	}*/

	/*int a = 5, b = 6;

	int arr[] = { 1, 10, 5, 6, 7 };
	Compare cmp(5);
	Compare cmp1(3);
	int* result = Find(arr, 5, cmp1);
	if (result)
	{
		std::cout << *result << "\n";
	}*/
	
	int arr[] = { 1, 8, 5, 6, 7 };
	Compare<int> cmp(5);
	Compare<int> cmp1(3);
	int* result = find(arr, 5, cmp1);
	if (result)
	{
		std::cout << *result << "\n";
	}

	Greater<float> great(5);
	int* result2 = find(arr, 5, great);
	if (result2)
	{
		std::cout << *result2 << "\n";
	}

	GreaterFromTwo<int> greaterFromTwo;

	BubbleSort(arr, 5, greaterFromTwo);

	int c = 3;
	plus(c, 2);
	plus(c);

	BubbleSort(arr, 5);

	Student studArray[] = { Student("Petrov", 5.0), Student("Ivanov", 3.4) };


	BubbleSort(studArray, 2, GreaterFromTwoStudentByRating());// 3 параметр передаем явно способ сортировки

	//BubbleSort(studArray, 2); без использования спец класса без 3го параметра

	return 0;
}
