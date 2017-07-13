//////////////////////////////////////////////////
#include <iostream>
#include <string>

int main()
{
	[] {
		std::cout << "hello lambda" << std::endl;
	};

	[] {
		std::cout << "Hello lambda" << std::endl;
	} (); // выводит на экран "Hello lambda"

	auto l = []
	{
		std::cout << "hello lambda" << std::endl;
	};

	l(); // выводит на экран "hello lambda"

	auto lam = [](std::string s)
	{
		std::cout << s << std::endl;
	};

	lam("Bazinga");

	//Лямбда функция не может быть шаблонная
	//Если тип возвращаемого значения не указан, он выводится из его значения

	[]
	{
		return 42;
	};//вернет тип int

	[]() ->double
	{
		return 42;
	}; //вернет 42.0 (тип double)

	int x = 0;
	int y = 34;

	auto printXY = [x, &y]//режим доступа к x по значению, к y по ссылке (можно еще так[=, &y])
	{
		std::cout << x << std::endl;//x нельзя модифицировать
		std::cout << y << std::endl;
		++y;
	};

	x = y = 77;
	printXY();
	printXY();
	std::cout << "Final y: " << y << std::endl;


	/////////////////////////////////
	//Применение mutable

	int id = 0;
	auto f = [id]() mutable //id передается по значению,но его можно изменить
	{
		std::cout << "id: " << id << std::endl;
		++id;
	};

	id = 42;
	f();
	f();
	f();
	std::cout << id << std::endl;
}

//////////////////////////////////////////////////
#include <iostream>
#include <functional>

std::function<int(int, int)> returnLambda()
{
	return [](int x, int y)
	{
		return x * y;
	};
};

int main()
{
	auto lf = returnLambda();
	std::cout << lf(6, 7) << std::endl;

}
///////////////////////////////////////////////////////////////

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
