#pragma once
#include <iosfwd>

class Time12
{
private:
	bool m_pm;
	int m_hour;
	int m_minute;

public:
	Time12();
	Time12(bool ap, int hour, int minute);
	void Show() const;
	//Time12(Time24);
};

class Time24
{
private:
	int hour;
	int minute;
	int second;

public:
	Time24();
	Time24(int h, int m, int s);
	void Show();
	operator Time12() const;
	int GetHour();
	int GetMinute();
	int GetSecond();
};
