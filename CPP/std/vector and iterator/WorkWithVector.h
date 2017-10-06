#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
class WorkWithVector
{
protected:
	typedef typename std::vector<T>::iterator my_it;
	my_it m_begin;
	my_it m_end;
public:
	WorkWithVector(my_it beg, my_it end)
	{
		m_begin = beg;
		m_end = end;
	}
	virtual my_it operator()() = 0;
};


template <typename T>
class MyFunctorMin : public WorkWithVector<T>
{
public:
	MyFunctorMin(my_it beg, my_it end) : WorkWithVector<T>(beg, end)
	{
	}

	my_it operator()() override
	{
		my_it min = m_begin;
		for (my_it it = m_begin; it != m_end; it++)
		{
			if (*(it) < *(min))
			{
				min = it;
			}
		}
		return min;
	}
};


template <typename T>
class MyFunctorMax : public WorkWithVector<T>
{
public:
	MyFunctorMax(my_it beg, my_it end) : WorkWithVector<T>(beg, end)
	{
	}

	my_it operator()() override
	{
		my_it max = m_begin;
		for (my_it it = m_begin; it != m_end; it++)
		{
			if (*(it) > *(max))
			{
				max = it;
			}
		}
		return max;
	}
};
