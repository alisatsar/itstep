#include <iostream>

template <class T>
void Print(const T& t)
{
	for (typename T::const_iterator it = t.begin(); it != t.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

int main()
{
	std::string str{ "hello world\n" };

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	for (auto it = str.begin(); it != str.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	for (auto &&s : str)
	{
		std::cout << s << std::endl;
	}

	Print<std::string>(str);
}
