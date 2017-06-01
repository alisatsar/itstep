#include "stack.h"

int main()
{
	Stack stack1;
	Stack stack2;

	stack1.Push(1);
	stack1.Push(2);
	stack1.Push(3);
	stack1.Push(4);
	stack1.Push(5);
	stack1.Push(6);
	stack1.Push(7);
	stack1.Push(8);
	stack1.Push(9);
	stack1.Push(10);
	stack1.Push(11);

	stack2 = stack1;

	int pop = stack2.Pop();

	int count = stack2.GetCount();

	int top = stack2.Top();

	stack2.Clear();

	stack2 << 3;

	int a = 8;
	stack2 >> a;

	return 0;
}
