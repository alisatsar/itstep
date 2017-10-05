/*
Создать класс умного указателя аналогичный shared_ptr, реализовать счётчик ссылок и возможность копирования.
Класс:
template<typename T>
class myshared<T>;
Реализовать функции:
Конструктор - myshared(T* ptr);
void reset(T* ptr);
long use_count() const;
T* get() const;
T& operator*() const;
T* operator->() const;
myshared& operator=(const myshared& other);
Дополнительно если есть желание:
Move constructor - myshared(myshared && other);
Конструктор -
template<typename Deleter>
myshared(T* ptr, Deleter d);
Функции -
template <typename Deleter>
void reset(T* ptr, Deleter deleter);
operator bool() const;
bool unique() const;*/

#include <iostream>
#include "SmartPointer.h"

int main()
{
	int i = 8;
	
	SmartPointer<int> pt = new int(i);
	int b = 9;
	pt.Reset(new int(b));

	std::cout << "The count of pointers: " << pt.UseCount() << std::endl;

	std::cout << *pt;	
	
	SmartPointer<int> pt2;

	pt2 = pt;	
}
