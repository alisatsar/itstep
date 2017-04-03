#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define COUNT_STRUCT 5

enum Menu
{
	Pay = 1,
	RefillBalans,
	PrintTransaction,
	ShowBalans,
	Exit
};

struct Transaction
{
	float Sum;
	char* To;
	char* Reason;
};

void cleanInput();
void chooseOperation(struct Transaction* transactions, enum Menu* menu, int* countString);

int main()
{
	struct Transaction* transactions = malloc(COUNT_STRUCT * sizeof(struct Transaction));
	enum Menu menu;
	int countString = 1;

	printf("Enter balans: \n");
	scanf("%f", &transactions[0].Sum);
	
	
	chooseOperation(transactions, &menu, &countString);
}

void chooseOperation(struct Transaction* transactions,  enum Menu* menu, int* countString)
{
	while (true)
	{
		printf("Choose the operation: \n");
		printf("1 = Pay\n2 = refill balans\n3 - print transaction\n4 - show balans");
		scanf("%i", menu);
		switch (*menu)
		{
		case Pay:
			printf("Enter sum: \n");
			scanf("%f", &transactions[*countString].Sum);

			printf("Enter the organization, that you want pay: ");
			transactions[*countString].To = malloc(30);
			fgets(transactions[*countString].To, 30, stdin);
			cleanInput();

			printf("Enter the reason, that you want pay: ");
			transactions[*countString].Reason = malloc(30);
			fgets(transactions[*countString].Reason, 30, stdin);
			countString++;
			break;
		case RefillBalans:
			printf("Enter balans: \n");
			scanf("%f", &transactions[*countString].Sum);
			transactions[*countString].To = NULL;
			transactions[*countString].Reason = NULL;
			countString++;
			break;
		case PrintTransaction:
			*countString = 0;
			for (int i = 0; i < *countString; i++)
			{
				printf("Sum: %f, organization %s, reason %s", transactions[*countString].Sum,
					transactions[*countString].To ? transactions[*countString].To : "-",
					transactions[*countString].Reason ? transactions[*countString].Reason : "-");
				countString++;
			}
		case Exit:
			return 0;
		}
	}
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}
