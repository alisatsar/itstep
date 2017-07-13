#include <ctime>
#include <iostream>
#include <chrono>

int const SecondsPerHour = 60 * 60;
int const SecondsPerDay = 24 * SecondsPerHour;

using namespace std::chrono;

int main()
{
	std::time_t current = std::time(nullptr);

	std::cout << "Seconds since epoch: " << current << std::endl;
	
	tm* _tm = localtime(&current);

	std::cout << "Local time: " << asctime(_tm);

	_tm = gmtime(&current);

	std::cout << "absolut time: " << asctime(_tm);

	std::cout << "today is " << _tm->tm_wday << " th day pf week" << std::endl;

	std::time_t currentPlusWeek = current + 7 * SecondsPerDay;

	std::cout << "local time: " << ctime(&currentPlusWeek); // time_t mktime(tm *_tm)

	//________________________

	system_clock::time_point tp = system_clock::now();
	time_t t = system_clock::to_time_t(tp);
	std::cout << "Local time: " << ctime(&t);


	system_clock::time_point tp1;
	t = system_clock::to_time_t(tp1);
	std::cout << "epoch time: " << ctime(&t);

	duration<long, std::ratio<1, 2>> halfSeconds(10);

	tp1 += halfSeconds;
	t = system_clock::to_time_t(tp1);
	std::cout << "Epoch time: " << ctime(&t);

	duration<long, std::ratio<60 * 60>> halfHour(3);
	tp1 += halfHour;
	t = system_clock::to_time_t(tp1);
	std::cout << "time: " << ctime(&t);

	//typedef duration<long, std::ratio<60>> minutes;

	tp1 += minutes(20);
	t = system_clock::to_time_t(tp1);
	std::cout << "time: " << ctime(&t);

	std::cout << (seconds(59) < minutes(1)) << std::endl;

	system_clock::time_point tpEnd = system_clock::now() +
		hours(24 * 7);

	t = system_clock::to_time_t(tpEnd);
	std::cout << "time: " << ctime(&t);

	typedef duration<long, std::ratio<60 * 60 * 24>> days;

	tpEnd += days(7);
	t = system_clock::to_time_t(tpEnd);
	std::cout << "2Week from now: " << ctime(&t);

	seconds sec(5000);

	int _h = sec / hours(1);
	sec -= _h * hours(1);

	//int _m = sec / minutes(1);
	minutes min = duration_cast<minutes>(sec);
	int _m = min.count();
	sec -= _m * minutes(1);

	std::cout << "5000 sec = " << _h << " hours, " << _m << " minutes, " << sec.count() << " seconds\n";


	return 0;
}
