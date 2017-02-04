/*Реализовать программу нахождения факториала числа(без рекурсии, т.е.вызова функции
самой себя).
Факториал числа — это произведение натуральных чисел от 1 до самого числа(включая
данное число).Примеры: 3!= 1 * 2 * 3 = 6. 6!= 1 * 2 * 3 * 4 * 5 * 6 = 720.
Пример прототипа функции : int getFactorial(int n);*/

#include <stdio.h>

long long getFactorial(int n);

int main()
{
	int userNumber;

	printf("Enter number, which factorial you want define:\n");
	scanf("%i", &userNumber);

	printf("Factorial number %i = %ld.\n", userNumber, getFactorial(userNumber));

}

long long getFactorial(int n)
{
	int result = 1;
	for (int i = 1; i < n + 1; i++)
	{
		result = result * i;
	}
	return result;
}
