#include <memory>
#include <iostream>
#include <cstring>


template<class T> //îáúÿâëåíèå îáùåãî êëàññû
class AccumulationTraits;


////ñïåöèëàçàöèè êëàññà AccumulationTraits
template<>
class AccumulationTraits<int>
{
public:
	typedef int AccT;
};

template<>//óêàçûâàåò ÷òî ýòî øàáëîí
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

template<class T>
T* find(T* array, int count, T const& element)
{
	for (int i = 0; i < count; i++)
	{
		if (array[i] == element)
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
bool Greater(T1 const& a, T2 const& b)
{
	return a >(T1)b;
}

bool Greater(int const& a, double const& b)
{
	return (double)a > b;
}

template<class T>
void BubbleSort(T* array, int count)
{
	for (int i = count - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				T buff = std::move(array[j]);
				array[j] = std::move(array[j + 1]);
				array[j + 1] = std::move(buff);
			}
		}
	}
}

int main()
{

	float a = 1.4;
	float b = 2.5;

	std::cout << max(a, b) << std::endl;

	char str[] = "asg";

	std::cout << (char)average(str, strlen(str)) << std::endl;

	return 0;
}
