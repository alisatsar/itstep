#include <stdio.h>
#include <stdlib.h>

//#define f\

/*int main()
{
	int i = 5;
	int* pI1 = &i;
	int* pI2 = &i;
	printf("%i\n", &i); //преведние адреса числа i в int
	printf("%i\n", pI1);
	printf("%i\n", pI2);
	printf("0x%p\n", pI2); // шестнадцатиричное значение

	printf("%i\n", *pI2); // получение значения хранящегося по адресу
}*/

/*int main()
{
	char a = 5;
	char* pA = &a;

	short b = 4;
	short* pB = &b;

	float c = 6.1;
	float* pC = &c;

	int d = 9;
	int* pD = &d;

	double e = 213155434151.34454;
	double* pE = &e;

	printf("0x%p\n", pA);
	printf("%i\n", *pA);
	printf("%i\n", sizeof(pA));

	printf("0x%p\n", pB);
	printf("%i\n", *pB);
	printf("%i\n", sizeof(pB));

	printf("0x%p\n", pC);
	printf("%f\n", *pC);
	printf("%i\n", sizeof(pC));

	printf("0x%p\n", pD);
	printf("%i\n", *pD);
	printf("%i\n", sizeof(pD));
	
	printf("0x%p\n", pE);
	printf("%f\n", *pE);
	printf("%i\n", sizeof(pE));
}*/

/*int main()
{
	int i = 5;
	int* pI1 = &i;
	int* pI2 = &i;
	printf("&i: %i\n", &i); //преведние адреса числа i в int
	printf("%i\n", pI1);
	printf("%i\n", pI2);
	printf("0x%p\n", pI2); // шестнадцатиричное значение

	printf("&i: %i\n", *pI2); // получение значения хранящегося по адресу
	
	*pI1 = 100;
	printf("&i: %i\n", i); //преведние адреса числа i в int
}*/

/*int main()
{
	int i = 3;
	int* pI1 = &i;
	
	(*pI1)++;
	printf("*pI1: %i\n", *pI1); // получение значения хранящегося по адресу

	*pI1 = 100;
	printf("&i: %i\n", i); //преведние адреса числа i в int
}*/

void getRandom(int* random);

int main()
{
	int i = 5;
	srand(&i);
	getRandom(&i); //передаем адрес

	printf("%i\n", i);
}
void getRandom(int* random) //записываем адрес по указателю
{
	*random = rand();
}
