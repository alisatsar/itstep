#pragma once
#include <vector>
#include <iterator>

template <typename T>
class MyFunctorMax
{
private:
	typedef typename std::vector<T>::iterator my_it;
	my_it m_begin;
	my_it m_end;
public:
	MyFunctorMax(my_it beg, my_it end) : m_begin(beg), m_end(end)
	{

	}


	my_it operator() (my_it beg, my_it end)
	{
		my_it max = beg;
		for (my_it it = beg; it != end; it++)
		{
			if (*(it) > *(max))
			{
				max = it;
			}
		}
		return max;
	}
};
