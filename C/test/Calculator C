/*Задание 1
Написать программу-калькулятор. Реализовать 4 основные арифметические действия над
2-мя целочисленными значениями, получаемыми от пользователя. Арифметическое
действие задается путем введения с клавиатуры символов ‘+’, ‘-’, '/', '*'.*/

#include <stdio.h>
#include <locale.h>

enum Action
{
	Sum = '+',
	Deduct = '-',
	Multiply = '*',
	Divide = '/'
};

int sum(int a, int b);
int deduct(int a, int b);
int multiply(int a, int b);
float divide(float a, float b);
float calculate(enum Action action, int a, int b);

int main()
{
	setlocale(LC_ALL, "russian");

	int a;
	int b;
		
	printf("Введите число a\n");
	scanf("%i", &a);
	printf("Введите число b\n");
	scanf("%i", &b);

	printf("Выберите действие:\n");
	printf("Сложить - +\nВычесть - -\nУмножить - *\nРазделить - /\n");
	
	enum Action action;
	do {
		action = getchar();
	} while (action != '\n' && action != EOF);
	scanf("%c", &action);

	printf("%.2f", calculate(action, a, b));
}

int sum(int a, int b)
{
	return a + b;
}

int deduct(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

float divide(float a, float b)
{
	if (b == 0)
	{
		printf("На ноль делить нельзя!!!\n");
		return 1;
	}
	else
	{
		return a / b;
	}
}

float calculate(enum Action action, int a, int b)
{
	float result;
	switch (action)
	{
	case Sum:
		result = sum(a, b);
		break;
	case Deduct:
		result = deduct(a, b);
		break;
	case Multiply:
		result = multiply(a, b);
		break;
	case Divide:
		result = devide(a, b);
		break;
	}
	return result;
}
