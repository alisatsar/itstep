#include <stdio.h>
#include <stdlib.h>

void checkPattern(int array[10], int* last, int* first, int* indexFirst, int* indexLast, int* count);
void checkPatternThree(int array[10], int* four, int* three, int* two, int* indexTwo, int* indexThree, int* indexFour, int* count);

int main()
{
	int array[10] = { 1, 3, 1, 2, 3, 1, 2, 3, 1, 2 };

	int indexFour = 0;
	int indexThree = 0;
	int count = 1;
	
	for (int i = 9; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[i] == array[j])
			{
				indexFour = i;
				indexThree = j;
				count++;
			}
			else if (array[i] != array[j])
			{
				int four = array[i];
				int three = array[j];
				printf("\n\n%i\n", four);
				printf("%i\n", three);
				indexThree = j;
				indexFour = i;
				checkPattern(array, &four, &three, &indexThree, &indexFour, &count);
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

	printf("%i\n", indexThree);
	printf("%i\n", indexFour);
	printf("%i\n", count);
}

void checkPattern(int array[10], int* four, int* three, int* indexThree, int* indexFour, int* count)
{
	printf("\n\n%i\n", *four);
	printf("%i\n", *three);
	for (int j = *indexThree; j >= 0; j = j - 2)
	{
		if (*four == array[j - 1] && *three == array[j - 2])
		{
			*indexFour = *indexFour;
			*indexThree = j - 2;
			*count = *count + 1;
		}
		else if (*four != array[j - 1] && *three != array[j - 1] && array[j - 4] == array[j - 1])
		{
			int two = array[j - 1];
			*four = array[j + 1];
			*three = array[j];
			printf("\n\n%i\n", *four);
			printf("%i\n", *three);
			printf("%i\n", two);
			int indexTwo = array[j - 1];
			*indexThree = j;
			*indexFour = j + 1;
			checkPatternThree(array, four, three, &two, &indexTwo, indexThree, indexFour, count);
			break;
		}
	} 
}

void checkPatternThree(int array[10], int* four, int* three, int* two, int* indexTwo, int* indexThree, int* indexFour, int* count)
{
	
	for (int k = *indexThree; k >= 0; k = k - 3)
	{
		if (*four == array[k - 1] && *three == array[k - 2] && *two == array[k - 3])
		{
			*indexFour = *indexFour;
			*indexThree = k - 2;
			*count = *count + 1;
		}
		else
		{
			break;
		}
		
	}
}
