#include <stdio.h>
#include <stdlib.h>

struct Buff
{
	int one;
	int two;
	int three;
	int four;
};

void checkPattern(int array[10], int* last, int* first, int* indexFirst, int* indexLast, int* count);

int main()
{
	int array[10] = { 1, 1, 2, 2, 3, 1, 2, 3, 1, 2 };

	struct Buff buff;

	int indexFirst = 0;
	int indexLast = 0;
	int count = 1;

	for (int i = 9; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[i] == array[j])
			{
				indexLast = i;
				indexFirst = j;
				count++;
			}
			else if (array[i] != array[j] && array[i] == array[j - 1])
			{
				buff.one = array[i];
				buff.two = array[j];
				indexFirst = j;
				indexLast = i;
				checkPattern(array, &buff.one, &buff.two, &indexFirst, &indexLast, &count);
				i = i - count;
				break;
			}
		}
		if (count > 1)
		{
			break;
		}
		if (count >= i / 2)
		{
			i = i - count;
		}
	}

	printf("%i\n", indexFirst);
	printf("%i\n", indexLast);
	printf("%i\n", count);
}

void checkPattern(int array[10], int* last, int* first, int* indexFirst, int* indexLast, int* count)
{
	for (int j = *indexFirst; j >= 0; j = j-2)
	{
		if (*last == array[j - 1] && *first == array[j - 2])
		{
			*indexLast = *indexLast;
			*indexFirst = j - 2;
			*count = *count + 1;
		}
		else
		{

			break;
		}
	}
}
