// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

void createFile()
{
	std::ofstream oFile("sont.txt", std::ios::out | std::ios::trunc);
	oFile << "We all live in a yellow submarine yellow submarine yellow submarine";
}

int main()
{
	std::vector<std::string> words;

	std::ifstream iFile("song.txt", std::ios::in);

	/*while (!iFile.eof()) //цикл до EOF
	{
		std::string buffer;
		iFile >> buffer;
		words.push_back(buffer);
	}*/

	std::copy(std::istream_iterator<std::string>(iFile),
		std::istream_iterator<std::string>(),
		std::back_inserter(words));

	std::function<bool(std::string const&)> lambda = [](std::string const& st)
	{
		char buff = st[0];
		
		if (buff == 'a' || buff == 'e' || buff == 'y' || buff == 'u'
			|| buff == 'i' || buff == 'o')
		{
			return true;
		}
		return false;
	};

	/*std::copy_if(std::istream_iterator<std::string>(iFile),
		std::istream_iterator<std::string>(),
		std::back_inserter(words), lambda);*/

	auto it = std::remove_if(words.begin(), words.end(), std::not1(lambda));

	words.erase(it, words.end());

	std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	auto iter = std::unique(words.begin(), words.end());

	words.erase(iter, words.end());

	std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	auto lambdaStr = [](std::string const& st1, std::string const& st2)
	{
		return st1.size() < st2.size();
	};

	std::sort(words.begin(), words.end(), lambdaStr);

	std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}
