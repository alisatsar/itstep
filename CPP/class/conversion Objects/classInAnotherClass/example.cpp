#include <iostream>
#include "example.h"
#include <cstring>

Time12::Time12():m_pm(true), m_hour(0), m_minute(0)
{
}

Time12::Time12(bool ap, int hour, int minute):m_pm(ap),
m_hour(hour), m_minute(minute)
{
}

void Time12::Show() const
{
	std::cout << m_hour << ":" << (m_minute < 10 ? "0" : "") << m_minute;
	std::cout << (m_pm ? "p.m" : "a:m") << std::endl;
}

/*Time12::Time12(Time24 t24)
{
	int hour24 = t24.GetHour();
	m_pm = hour24 < 12 ? false : true;

	m_minute = (t24.GetSecond() < 30) ? t24.GetMinute() : t24.GetMinute() + 1;

	if (m_minute == 60)
	{
		m_minute = 0;
		++hour24;
		if (hour24 == 12 || hour24 == 24)
		{
			m_pm = (m_pm == true) ? false : true;
		}
	}

	m_hour = (hour24 < 13) ? hour24 : hour24 - 12;

	if (m_hour == 0)
	{
		m_hour = 12;
		m_pm = false;
	}
}*/


Time24::Time24():hour(0), minute(0), second(0)
{
}

Time24::Time24(int h, int m, int s):
	hour(h), minute(m), second(s)
{
}

void Time24::Show()
{
	std::cout << (hour < 10 ? "0" : "") << hour << ":" <<
		(minute < 10 ? "0" : "") << minute << ":" <<
		(second < 10 ? "0" : "") << second << std::endl;
}


///////////CONVERSION CLASS IN ANOTHER CLASS///////////
Time24::operator Time12() const
{
	int hour24 = hour;
	bool pm = hour < 12 ? false : true;

	int roundMins = second < 30 ? minute : minute + 1;

	if (roundMins == 60)
	{
		roundMins = 0;
		++hour24;
		if (hour24 == 12 || hour24 == 24)
		{
			pm = (pm ? false : true);
		}
	}

	int hour12 = (hour24 < 13) ? hour24 : hour24 - 12;

	if (hour12 == 0)
	{
		hour12 = 12;
		pm = false;
	}
	return Time12(pm, hour12, roundMins);
}
////////////////////////////////////////////////////////

int Time24::GetHour()
{
	return hour;
}

int Time24::GetMinute()
{
	return minute;
}

int Time24::GetSecond()
{
	return second;
}
