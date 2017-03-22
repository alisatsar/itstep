oid fit(char* string, int unsigned size);

int main()
{
	char m[] = "All should be maximum simple" " ,but not more";
	puts(m);
	fit(m, 28);
	puts(m);
	puts("Lets look more string");
	puts(m + 30); //покажет m[30]
}

void fit(char* string, int unsigned size)
{
	if (strlen(string) > size)
	{
		string[size] = '\0';
	}
}
