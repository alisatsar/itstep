#pragma once

template<class T, int N>
class Array
{
public:
	T m_array[N];
	Array();

	/*в классе
	template<int N1>
	Array(Array<T, N1> const& rhs)
	{
		for (int i = 0; i < N1; i++)
		{
			m_array[i] = i < N1 ? rhs.m_array[i] : T(); //T() конструктор по умолчанию, который заполняется 0
		}
	}*/

	template<int N1>
	Array(Array<T, N1> const& rhs);

	T& operator[](int ind);
	int GetSize() const;

	template<int N1>
	Array<T, N>& operator=(const Array<T, N1>& rhs);
};

template<class T, int N>
template<int N1>
Array<T, N>& Array<T, N>::operator=(const Array<T, N1>& rhs)
{
	if ((void*)this != (void*)&rhs)
	{
		for (int i = 0; i < N; ++i)
		{
			m_array[i] = i < N1 ? rhs.m_array[i] : T();
		}
	}
	return *this;
}


//за классом
template<class T, int N>
template<int N1>
Array<T, N>::Array(const Array<T, N1>& rhs)
{
	for (int i = 0; i < N; ++i)
	{
		m_array[i] = i < N1 ? rhs.m_array[i] : T();
	}
}

template<class T, int N>
Array<T, N>::Array()
{
	memset(m_array, 0, N);
}

template<class T, int N>
T& Array<T, N>:: operator[](int ind)
{
	if (ind < 0 || ind >= N)
	{
		std::cout << "Invalid index!\n";
	}
	return m_array[ind];
}

template<class T, int N>
int Array<T, N>::GetSize() const
{
	return N;
}
