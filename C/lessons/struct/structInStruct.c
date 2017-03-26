#include <stdio.h>

#define LEN 40

const char *msgs[5] =
{
	"Thank you for wonderful day, ",
	"You are definitely demonstrate, that ",
	"you are perfect man. We are should meet up",
	"for wonderful dinner with",
	"and have the fun time."
};

struct names
{
	char first[LEN];
	char last[LEN];
};

struct guy
{
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main()
{
	struct guy fellow =
	{
		{ "Billy", "Bons" },
		"eat the omar", "personal trener", 68112.0
	};
	printf("Dear %s, \n\n", fellow.handle.first);
	printf("%s%s.\n", msgs[0], fellow.handle.first);
	printf("%s%s\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s %s %s", msgs[3], fellow.favfood, msgs[4]);
	if (fellow.income > 150000.0)
	{
		puts("!!");
	}
	else if (fellow.income > 75000.0)
	{
		puts("!");
	}
	else
	{
		puts(".");
	}
	printf("\n%40s%s\n", " ", "See you soon,");
	printf("%40s%s\n", " ", "Anna");
}
