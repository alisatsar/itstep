/*Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и
играющий должен угадать его. После ввода пользователем числа программа сообщает,
сколько цифр числа угадано (быки) и сколько цифр угадано и стоит на нужном месте
(коровы). После отгадывания числа на экран необходимо вывести количество сделанных
пользователем попыток. В программе необходимо использовать рекурсию.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int userGuess(int computerNumber, int try);
int countCows(int userNumber, int computerNumber);
int countBulls(int userNumber, int computerNumber);

int main()
{
	int computerNumber;
	int try = 0;
				
	srand(time(0));
	computerNumber = rand() % 9000 + 1000;
	
	printf("The computer guessed the number from 1000 to 9999!\n");
	printf("Bulls - this is how number you guess.\n");
	printf("cows are how numbers is on the right place.\n");

	int countTry = userGuess(computerNumber, try);
	
	printf("Try = %i\n", countTry);
	printf("Computer number is %i\n", computerNumber);
}

int userGuess(int computerNumber, int try)
{
	int userNumber;
	int cow = 0;
	int bull = 0;
	try ++;
	
	printf("Please, enter you number: ");

	scanf("%i", &userNumber);
	
	printf("bull = %i\n", countBulls(userNumber, computerNumber));
	printf("cow = %i\n", countCows(userNumber, computerNumber));
	
	if (cow != 4)
	{
		int continueOrExit;
		printf("if You wanna exit from programm, press ""1"". Or ""2"" to continue:\n");
		scanf("%i", &continueOrExit);
		if (continueOrExit == 1)
		{
			return try;
		}
		else
		{
			userGuess(computerNumber, try);
		}
	}
	if (cow == 4)
	{
		printf("Congratylasion! You are guess computer number!\n");
		return try;
	}
}

int countCows(int userNumber, int computerNumber)
{
	int cow = 0;
	int numberAUser;
	int numberBUser;
	int numberCUser;
	int numberDUser;

	for (int i = 0; i < 4; i++)
	{
		int ostotokComputer = computerNumber % 10;
		int ostotokUser = userNumber % 10;
		if (ostotokUser == ostotokComputer)
		{
			cow++;
		}
		if (i == 0)
		{
			numberAUser = ostotokUser;
		}
		if (i == 1)
		{
			numberBUser = ostotokUser;
		}
		if (i == 2)
		{
			numberCUser = ostotokUser;
		}
		if (i == 3)
		{
			numberDUser = ostotokUser;
		}
		computerNumber = computerNumber / 10;
		userNumber = userNumber / 10;
	}
	return cow;
}

int countBulls(int userNumber, int computerNumber)
{
	int bull = 0;
	int numberAUser = userNumber / 1000;
	int numberBUser = userNumber % 1000 / 100;
	int numberCUser = userNumber % 100 / 10;
	int numberDUser = userNumber % 10;

	for (int i = 0; i < 4; i++)
	{
		int ostotokComputer = computerNumber % 10;
		if ((ostotokComputer == numberAUser) || (ostotokComputer == numberBUser)
			|| (ostotokComputer == numberCUser) || (ostotokComputer == numberDUser))
		{
			bull++;
		}
		computerNumber = computerNumber / 10;
	}
	return bull;
}
