//1. Код нормально выполняется вне блока повторных попыток.
//2. Управление переходит в блок повторных попыток.
//3. Какое - то выражение в этом блоке приводит к возникновению ошибки в методе.
//4. Метод генерирует исключение.
//5. Управление переходит к обработчику ошибок(улавливающему блоку), следующему сразу за блоком повторных попыток.

____________________________________________________________________________________________________________________

#include <iostream>

const int MAX = 3;

class Stack
{
private:
	int st[MAX];
	int top;
public:
	class Range
	{
	};

	Stack()
	{
		top = -1;
	}

	void Push(int var)
	{
		if (top >= MAX - 1)
		{
			throw Range();
		}
		st[++top] = var;
	}

	int Pop()
	{
		if (top < 0)
		{
			throw Range();
		}
		return st[top--];
	}
 };

int main()
{
	Stack s1;

	try
	{
		s1.Push(11);
		s1.Push(22);
		s1.Push(33);
		//s1.Push(44);
		std::cout << "1: " << s1.Pop() << std::endl;
		std::cout << "2: " << s1.Pop() << std::endl;
		std::cout << "3: " << s1.Pop() << std::endl;
		std::cout << "4: " << s1.Pop() << std::endl;
	}
	catch (Stack::Range)
	{
		std::cout << "exception: stack is over of empty" << std::endl;
	}
	std::cout << "This string was to print console, because we are add exceptions!";
	return 0;
}
