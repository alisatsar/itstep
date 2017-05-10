#include <stdio.h>
#include <stdbool.h>

#define НАЧАЛО_ПРОГРАММЫ int main()\
{
#define НАЧАЛО_БЕСКОНЕЧНОГО_ЦИКЛА while (true)\
{
#define КОНЕЦ_БЕСКОНЕЧНОГО_ЦИКЛА }

НАЧАЛО_ПРОГРАММЫ
	НАЧАЛО_БЕСКОНЕЧНОГО_ЦИКЛА
		printf("Hello");
	КОНЕЦ_БЕСКОНЕЧНОГО_ЦИКЛА
}
