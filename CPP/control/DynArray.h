#pragma once

#include <iostream>
#include <initializer_list>

template<class T>
class DynArrayIterator
{
private:
	T* index = nullptr;
public:
	DynArrayIterator(T* index);
	T& operator*()
	{
		return *index;
	}

	DynArrayIterator<T> operator++()
	{
		return DynArrayIterator<T>(index + 1);
	}
};

template<class T>
class DynArray
{
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;

public:
	typedef DynArrayIterator<T> iterator;
	DynArray() = default;
	DynArray(size_t capacity);
	DynArray(DynArray const& rhs);
	DynArray(DynArray&& rhs);
	DynArray(std::initializer_list<T> const& list);
	DynArray& operator=(DynArray const& rhs);
	DynArray& operator=(DynArray&& rhs);

	void reserve(size_t newCapacity);
	size_t Size() const;
	size_t Capacity() const;

	void PushBack(T const& item);
	void PopBack();
	void Clear();

	T& operator[](size_t idx);
	T const& operator[](size_t idx) const;

	iterator begin();
	iterator end();

	iterator operator++();
	iterator operator--();

	bool operator==(DynArray const& rhs);

	int ReturnIndex(DynArrayIterator<T> const& it);

	//void Insert(iterator const& it, T const& element);
};

template<class T>
DynArray<T>::DynArray(size_t capacity) :
	m_capacity(capacity)
{
	if (m_capacity > 0)
	{
		m_data = new T[m_capacity];
	}
}

template<class T>
DynArray<T>::DynArray(DynArray const& rhs) :
	m_capacity(rhs.m_capacity),
	m_size(rhs.m_size)
{
	if (m_capacity > 0)
	{
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_size; ++i)
		{
			m_data[i] = rhs.m_data[i];
		}
	}
}

template<class T>
DynArray<T>::DynArray(DynArray&& rhs) :
	m_capacity(rhs.m_capacity),
	m_size(rhs.m_size),
	m_data(rhs.m_data)
{
	rhs.m_capacity = 0;
	rhs.m_size = 0;
	rhs.m_data = nullptr;
}

template<class T>
DynArray<T>::DynArray(std::initializer_list<T> const& list)
{
	size_t size = list.size();
	if (size > 0)
	{
		m_size = m_capacity = size;
		m_data = new T[m_capacity];
		T* ptr = m_data;
		typedef typename std::initializer_list<T>::iterator iterator;
		for (iterator it = list.begin(); it != list.end(); ++it)
		{
			*(ptr++) = *it;
		}
	}
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T> const& rhs)
{
	if (&rhs != this)
	{
		DynArray<T> temp(rhs);      // copy to temp
		*this = std::move(temp);    // grabbing data from temp
	}
	return *this;
}

template<class T>
DynArray<T>& DynArray<T>::operator=(DynArray<T>&& rhs)
{
	if (&rhs != this)
	{
		delete[] m_data;
		m_capacity = rhs.m_capacity;
		m_size = rhs.m_size;
		m_data = rhs.m_data;

		rhs.m_capacity = 0;
		rhs.m_size = 0;
		rhs.m_data = nullptr;
	}
	return *this;
}

template<class T>
void DynArray<T>::reserve(size_t newCapacity)
{
	if (m_capacity == newCapacity)
	{
		return;
	}

	m_capacity = newCapacity;
	if (m_size > m_capacity)
	{
		m_size = m_capacity;
	}
	DynArray<T> buff(*this);
	*this = std::move(buff);
}

template<class T>
size_t DynArray<T>::Size() const
{
	return m_size;
}

template<class T>
size_t DynArray<T>::Capacity() const
{
	return m_capacity;
}

template<class T>
void DynArray<T>::PushBack(T const& item)
{
	if (m_size == m_capacity)
	{
		reserve(m_capacity > 0 ? m_capacity * 2 : 5);
	}
	m_data[m_size++] = item;
}

template<class T>
void DynArray<T>::PopBack()
{
	if (m_size)
	{
		--m_size;
		if (m_size < m_capacity / 4)
		{
			reserve(m_capacity / 2);
		}
	}
}

template<class T>
void DynArray<T>::Clear()
{
	if (m_capacity > 0)
	{
		m_capacity = 0;
		delete[] m_data;
		m_data = nullptr;
		m_size = 0;
	}
}

template<class T>
T& DynArray<T>::operator[](size_t idx)
{
	if (idx >= m_size || idx < 0)
	{
		std::cout << "Invalid index\n" << idx << std::endl;
		exit(1);
	}
	return m_data[idx];
}

template<class T>
T const& DynArray<T>::operator[](size_t idx) const
{
	DynArray<T>* nonConstThis = const_cast<DynArray<T>*>(this);
	return (*nonConstThis)[idx];
}

template<class T>
DynArrayIterator<T> DynArray<T>::begin()
{
	DynArrayIterator<T> it(m_data);
	return it;
}

template<class T>
DynArrayIterator<T> DynArray<T>::end()
{
	DynArrayIterator<T> it(m_data + m_size);
	return it;
}

/*template<class T>
void DynArray<T>::Insert(iterator const& it, T const& element)
{
int position = it.(*index);
std::cout << position;
}*/

template<class T>
DynArrayIterator<T> DynArray<T>::operator++()
{
	T* ptr = m_data;
	DynArrayIterator<T> it;
	it.index = ptr;
	if (this->ReturnIndex(it) < m_size - 1)
	{
		it.index = ++m_data;
	}
	else
	{
		std::cout << "The wrong index, operator ++ can not be applied\n";
	}
	return it;
}

template<class T>
DynArrayIterator<T> DynArray<T>::operator--()
{
	T* ptr = m_data;
	DynArrayIterator<T> it;
	it.index = ptr;
	int index = this->ReturnIndex(it);
	if (index < m_size && index > 0)
	{
		it.index = --m_data;
	}
	else
	{
		std::cout << "The wrong index, operator -- can not be applied\n";
	}
	return it;
}

template<class T>
int DynArray<T>::ReturnIndex(DynArrayIterator<T> const& it)
{
	DynArrayIterator<T> iter = this->begin();
	T* ptr = iter.index;
	int i = 0;
	for (; i < m_size; i++)
	{
		if (ptr == it.index)
		{
			return i;
		}
		ptr++;
	}
	return 0;
}
