#pragma once
#include <iostream>
#include <tuple>

template <std::size_t> struct int_{};//создаем шаблонную структуру int

//int_<2>();

template <class Tuple>
std::ostream& PrintTyple(std::ostream& out, const Tuple& t, int_<1>)
{	
	return out << std::get<std::tuple_size<Tuple>::value-1>(t);
}

template <class Tuple, std::size_t Pos>
std::ostream& PrintTyple(std::ostream& out, const Tuple& t, int_<Pos>)
{
	out << std::get<std::tuple_size<Tuple>::value-Pos>(t) << ", ";
	return PrintTyple(out, t, int_<Pos-1>());
}
//std::tuple_size возвращает размер кортежа по типу
//std::tuple_size<std::tuple<int, int, int, int, int, int>>::value
//происходит на стадии компиляции


template <class... Args>
std::ostream& operator<<(std::ostream& stream, const std::tuple<Args...>& t)
{
	stream << "(";
	PrintTyple(stream, t, int_<sizeof...(Args)>());
	return stream << ")";
}
