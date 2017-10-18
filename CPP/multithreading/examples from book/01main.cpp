#include <iostream>
#include <thread>

void Hello()//в каждом потоке должна быть начальная функция, которая начинает исполнения потока
{
	std::cout << "Hello, parallel world\n";
}

int main()
{
	std::thread t(Hello);
	t.join();//Завтавляет ждать вызывающий поток(main()) окончание потока t
}
