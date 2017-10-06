#pragma once
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
class SortBegin
{
private:
	typedef typename std::vector<T>::iterator my_it;
	my_it m_begin;
	my_it m_end;
public:
	SortBegin(my_it beg, my_it end) : m_begin(beg), m_end(end)
	{

	}

	void operator()()
	{
		std::sort(m_begin, m_end);
	}
};