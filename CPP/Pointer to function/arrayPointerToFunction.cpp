#include <iostream>

const double* f1(const double ar[], int n)
{
	return ar;
}

const double* f2(const double* ar, int n)
{
	return ar + 1;
}

const double* f3(const double* ar, int n)
{
	return ar + 2;
}

int main()
{
	double ar[3] = { 1.2, 2.2, 3.3 };

	//указатель на функцию
	const double *(*p1)(const double*, int) = f1;

	auto p2 = f2;

	std::cout << "Adress   Value\n";
	std::cout << p1(ar, 3) << ":" << *p1(ar, 3) << std::endl;
	std::cout << (*p2)(ar, 3) << ":" << *(p2)(ar, 3) << std::endl;

	//pa - массив указателей
	//auto не работает со списковой инициализацией
	const double* (*pa[3])(const double*, int) = { f1, f2, f3 };

	//но рабоатем с инициализацией единственным значением
	//pb - указатель на первый элемент pa
	auto pb = pa;

	std::cout << "Adress   Value\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << pa[i](ar, 3) << ":" << (*pa[i](ar, 3)) << std::endl;
	}
}
