#pragma once
#include <iostream>

const int Diaposone = 256;

class HashTable
{
private:
	struct Data
	{
		std::string name;
		int value;
		Data* next;

		Data() = default;

		Data(std::string n, int v)
		{
			name = n;
			value = v;
			next = nullptr;
		}
	};

	Data* ar[Diaposone];

public:
	HashTable() = default;
	
	void Add(std::string name, int v)
	{
		Data d(name, v);

		std::hash<std::string> hash;

		size_t hashInt = hash(name);

		int newHash = hashInt % 256;

		Data cur = *ar[newHash];

		while (!cur.name.empty())
		{
			ar[newHash]->next = &d;
		}

	}
};
