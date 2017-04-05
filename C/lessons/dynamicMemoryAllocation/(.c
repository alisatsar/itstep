#include <stdlib.h>
#include <stdbool.h>

struct St
{
	float f1;
	struct St* next;
};

void prinSt(struct St* list)
{
	while (list != NULL)
	{
		printf("%f\n", list->f1);
		list = list->next;
	}
}

void main()
{
	struct St* st = malloc(sizeof(struct St));
	st->f1 = 98.55;

	struct St* st2 = malloc(sizeof(struct St));
	st2->f1 = 55.55;

	st->next = st2;
	

	struct St* st3 = malloc(sizeof(struct St));
	st3->f1 = 12.23;
	st3->next = NULL;

	st2->next = st3;

	prinSt(st);
}
