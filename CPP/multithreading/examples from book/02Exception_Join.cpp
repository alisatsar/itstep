#include <iostream>
#include <thread>

struct Func
{
	int& i;

	Func(int& value) : i(value)
	{
	}

	void operator()()
	{
		for (unsigned j = 0; j < 10; j++)
		{
			std::cout << i;
		}
	}
};

void oops()
{
	int someLocalState = 0;
	Func f1(someLocalState);
	std::thread t(f1);
	try
	{
		std::cout << "1";
	}
	catch (std::exception ex)
	{
		t.join();
		throw;
	}
	t.join();
}

int main()
{
	oops();
}
