#include <iostream>
#include <memory>
#include <string>
#include <algorithm>


template<typename T>
class DynArray
{
private:
	template<typename Iter>
	class DynArrayIterator
	{
		friend class DynArray;
	public:
		typedef Iter iterator_type;
		typedef std::random_access_iterator_tag iterator_category;
		typedef iterator_type value_type;
		typedef iterator_type& reference;
		typedef iterator_type* pointer;
		typedef std::ptrdiff_t difference_type;

		iterator_type* value;

	private:
		DynArrayIterator(Iter* pointer) : value(pointer) {}
	public:
		DynArrayIterator(DynArrayIterator const& rhs) : value(rhs.value) {}

		typename DynArrayIterator::reference operator*() const
		{
			return *value;
		}

		bool operator==(DynArrayIterator<Iter> const& iterator) const
		{
			return this->value == iterator.value;
		}

		bool operator!=(DynArrayIterator<Iter> const& iterator) const
		{
			return !(*this == iterator);
		}
		
		DynArrayIterator& operator++()
		{
			Iter* ptr = this->value;
			ptr += 1;
			this->value = ptr;
			return *this;
		}

		DynArrayIterator<iterator_type> operator+(int step)
		{
			iterator_type* ptr = this->value;
			ptr += step;
			this->value = ptr;
			return *this;
		}

		DynArrayIterator<iterator_type> operator-(int step)
		{
			iterator_type* ptr = this->value;
			ptr = ptr - step;
			this->value = ptr;
			return *this;
		}
	};
private:
	T* m_data = nullptr;
	size_t m_size = 0;
public:
	DynArray() = default;

	DynArray(size_t size) : m_size(size)
	{
		m_data = new T[m_size];
	}

	~DynArray()
	{
		delete[] m_data;
	}

	DynArray(DynArray const& rhs)
	{
		m_size = rhs.m_size;
		m_data = new T[m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = rhs.m_data[i];
		}
	}

	DynArray(DynArray&& rhs) :
		m_size(rhs.m_size),
		m_data(rhs.m_data)
	{
		rhs.m_size = 0;
		rhs.m_data = nullptr;
	}

	DynArray& operator=(DynArray const& rhs)
	{
		if (&rhs != this)
		{
			this->m_size = rhs.m_size;
			this->m_data = new T(this->m_size);
		}
		return *this;
	}

	T& operator[](size_t index)
	{
		if (index >= m_size || index < 0)
		{
			std::cout << "Invalid index\n" << index << std::endl;
			exit(1);
		}
		return m_data[index];
	}

	T const& operator[](size_t idx) const
	{
		DynArray<T>* nonConstThis = const_cast<DynArray<T>*>(this);
		return (*nonConstThis)[idx];
	}

	typedef DynArrayIterator<T> iterator;
	typedef DynArrayIterator<const T> const_iterator;

	iterator begin()
	{
		return iterator(m_data);
	}

	iterator end()
	{
		return iterator(m_data + m_size - 1);
	}

	const_iterator begin() const
	{
		return const_iterator(m_data);
	}

	const_iterator end() const
	{
		return iterator(m_data + m_size - 1);
	}

	friend std::ostream& operator<<(std::ostream& os, iterator it)
	{
		return os << *it;
	}
};

int main()
{
	
	DynArray<int> d2(5);

	DynArray<int>d3 = d2;

	DynArray<int> d1;

	d1 = d2;

	auto ptr = d2.begin();

	auto ptr2 = d2.end();

	++ptr;

	DynArray<int> from_vector(10);

	for (size_t i = 0; i < 10; i++)
	{
		from_vector[i] = i;
	}

	std::cout << ++from_vector.begin();

	for (auto &&it : from_vector)
	{
		std::cout << it;
	}
	
	bool b = from_vector.begin() != from_vector.end();
	
	DynArray<int> to_vector(11);
	std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());

	//std::sort(from_vector.begin(), from_vector.end());
}

//http://en.cppreference.com/w/cpp/concept/RandomAccessIterator
