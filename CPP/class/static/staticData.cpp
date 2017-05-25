#include <iostream>

class Foo
{
private:
	static int count;
	int suit = 0;

public:
	Foo()
	{
		count++;
		suit++;
	}

	int getCount()
	{
		return count;
	}

	int getSuit()
	{
		return suit;
	}
};

int Foo::count = 0;		//Только статические данные класса могут быть инициализированы вне класса

int main()
{
	Foo f1;
	Foo f2;
	Foo f3;

	std::cout << f1.getCount() << f1.getSuit();
	std::cout << f2.getCount() << f2.getSuit();
	std::cout << f3.getCount() << f3.getSuit();
	
	return 0;
}
