#include <stdio.h>

int main()
{
	int array[10] = {1, 2, 3, 4, 2, 3, 5, 2, 1, 1};

	/*int buffArray[2];

	memset(array, 2, 10);*/

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
			else
			{
				break;
			}
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
