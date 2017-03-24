struct CarStruct
{
	char model[50];
	char make[50];
	int year;
};

union car
{
	char model[50];
	char make[50];
	int year;
};

int main()
{
	union car car1;
	strcpy(car1.model, "x5");
	
	union car car2;
	strcpy(car2.make, "BMW");

	printf("%s", car1.model);
	printf("%s", car2.make);

	printf("%i\n", sizeof(struct CarStruct));
	printf("%i\n", sizeof(union car));
}
