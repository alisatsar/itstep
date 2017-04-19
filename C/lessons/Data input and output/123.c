#include <stdio.h>

#define STRING_SIZE 50

void writeStringToFile(char* firstName, char* lastName, char* middleName);
void readStringFromFile(char* firstName, char* lastName, char* middleName);

int main()
{
	char* firstName = malloc(STRING_SIZE);
	char* lastName = malloc(STRING_SIZE);
	char* middleName = malloc(STRING_SIZE);

	strcpy(firstName, "Hello");
	strcpy(lastName, "rldasfasf");
	strcpy(middleName, "Hello fgagworld");
	
	writeStringToFile(firstName, lastName, middleName);
			
	memset(firstName, 0, STRING_SIZE);
	memset(lastName, 0, STRING_SIZE);
	memset(middleName, 0, STRING_SIZE);
		
	readStringFromFile(firstName, lastName, middleName);
	
	free(firstName);
	free(lastName);
	free(middleName);
}

void writeStringToFile(char* firstName, char* lastName, char* middleName)
{
	FILE* f = fopen("D:\\binary.bin", "wb");

	char* buff = malloc(170);

	memset(buff, 0, 170);

	fwrite(buff, 170, 1, f);
			
	fseek(f, 0, SEEK_SET);

	fwrite(firstName, STRING_SIZE, 1, f);

	fseek(f, 58 - 49, SEEK_CUR);

	fwrite(lastName, STRING_SIZE, 1, f);

	fseek(f, 120 - 99, SEEK_CUR);

	fwrite(middleName, STRING_SIZE, 1, f);

	fclose(f);
}

void readStringFromFile(char* firstName, char* lastName, char* middleName)
{
	FILE* f = fopen("D:\\binary.bin", "rb");

	fseek(f, 0, SEEK_SET);

	fread(firstName, 50, 1, f);

	printf("%s", firstName);

	fseek(f, 0, SEEK_SET);

	fread(lastName, 50, 1, f);

	printf("%s", lastName);

	fseek(f, 0, SEEK_SET);

	fread(middleName, 50, 1, f);

	printf("%s", middleName);
	

	fclose(f);
}
