#include <iostream>
#include <thread>

class ThreadGuard
{
	std::thread& t;
public:
	explicit ThreadGuard(std::thread& value) : t(value)//explicit возможно только форма ThreadGuard g(std::thread t);
	{
	}

	~ThreadGuard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}

	ThreadGuard(ThreadGuard const&) = delete;
	ThreadGuard& operator=(ThreadGuard const&) = delete;
};

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
	Func f(someLocalState);
	std::thread t(f);
	ThreadGuard g(t);
	std::cout << "hello";
}

int main()
{
	oops();
}
