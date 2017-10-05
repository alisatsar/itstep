#pragma once
#include <iostream>

template<class T>
class SmartPointer
{
private:
	T* m_ptr = nullptr;	
	int m_count = 0;

public:
	SmartPointer() = default;
	SmartPointer(T* ptr);
	~SmartPointer();
	void Reset(T* ptr);
	long UseCount() const;
	T* Get() const;
	T& operator*() const;
	T* operator->() const;
	SmartPointer& operator=(const SmartPointer& other);
	SmartPointer(SmartPointer<T> && other);
};

template<class T>
SmartPointer<T>::SmartPointer(T* ptr) :
	m_ptr(ptr)
{	
	m_count = 1;
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
	if (m_count == 1)
	{
		delete m_ptr;		
	}	
	m_count = 0;
}

template<class T>
void SmartPointer<T>::Reset(T* ptr)
{
	delete m_ptr;
	m_ptr = ptr;
}

template<class T>
long SmartPointer<T>::UseCount() const
{
	return m_count;
}

template<class T>
T* SmartPointer<T>::Get() const
{
	return m_ptr;
}

template<class T>
T& SmartPointer<T>::operator*() const
{
	return *(m_ptr);
}

template<class T>
T* SmartPointer<T>::operator->() const
{
	return *(m_ptr);
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& other)
{
	delete m_ptr;	
	m_ptr = other.m_ptr;	
	m_count = other.m_count + 1;
	return *this;
}

template<class T>
SmartPointer<T>::SmartPointer(SmartPointer<T> && other)
{
	delete m_ptr;
	m_ptr = other;
	m_coutn = other.m_count;
	return this;
}
