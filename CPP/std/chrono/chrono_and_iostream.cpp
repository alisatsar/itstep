#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <ctime>

int main()
{
	//обрабатываем и выводим на печать текущую дату и время
	auto now = std::chrono::system_clock::now();
	time_t t = std::chrono::system_clock::to_time_t(now);

	tm* nowTM = localtime(&t);

	std::cout << std::put_time(nowTM, "date:%x\ntime: %X\n") << std::endl;

	//считываем дату
	tm date;
	std::cout << "new date: ";
	std::cin >> std::get_time(&date, "%x"); //считываем дату

	if (!std::cin)
	{
		std::cerr << "invalid format read" << std::endl;
	}
}
