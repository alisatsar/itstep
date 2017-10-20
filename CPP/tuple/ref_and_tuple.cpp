#include <iostream>
#include <functional>//ref cref
#include <utility>// pair
#include <tuple>

int main()
{
	std::string s = "Z";
	std::tuple<std::string&> t(s);//t = "Z"

	std::get<0>(t) = "bad";//t = "bad"
