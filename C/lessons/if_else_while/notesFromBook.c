#include <stdio.h>

int main()
{
	int const freezing = 0;
	float temperature;
	int coldDays = 0;
	int allDays = 0;
	
	printf("Enter the list of minimal temperature: \n");
	printf("For exit enter q\n");
	while (scanf("%f", &temperature) == 1)
	{
		allDays++;
		if (temperature < freezing)
			coldDays++;
	}

	if (allDays != 0)
		printf("%i = avarege days: %.lf%% with temperature below null\n",
			allDays, 100.0 * (float)coldDays / allDays);
	if (allDays == 0)
		printf("The date not enter\n");
}
#include <stdio.h>
#define SPACE ' '

int main()
{
	char ch;
	ch = getchar();		//читать символ
	//пока не встретиться \n можно написать так while ((ch = getchar() )!= '\n')
	while (ch != '\n')		
	{
		if (ch == SPACE)
		{
			putchar(ch);
		}
		else
		{
			putchar(ch + 1); //вывести следующий символ
		}
		ch = getchar();
	}
	putchar(ch);
}

