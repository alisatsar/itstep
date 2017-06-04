#pragma once

const int LIMIT = 10;

class SafeArray
{
private:
	int array[LIMIT];

public:
	void Putel(int n, int elvalue);
	int Getel(int n) const;
	int& access(int n);
	int& operator[](int n);
};
