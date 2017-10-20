#include <iostream>
#include <functional>//ref cref
#include <utility>// pair
#include <tuple>

int main()
{
	int i = 0;
	auto p = std::make_pair(std::ref(i), std::ref(i));//создает pair<int&, int&>
	++p.first;
	++p.second;
	std::cout << "i: " << i << std::endl;
	std::cout << p.first << std::endl;
	std::cout << p.second << std::endl;	
}
