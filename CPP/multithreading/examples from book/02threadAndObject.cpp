#include <iostream>
#include <thread>

class BackgroundTask
{
public:
	void operator()()const
	{
		std::cout << "hello\n";
	}
};

int main()
{
	BackgroundTask f;
	std::thread myThread(f);//можно передать экзамляр класса, в котором определен operator()
	//или так
	std::thread m2((BackgroundTask()));
	//или так
	std::thread m3{ BackgroundTask() };
	
	//////////////

	//с помощью лямбда выражений можно записать так
	std::thread mLambda([] {std::cout << "hello"; });

	myThread.join();
	m2.join();
	m3.join();
	mLambda.join();
}
