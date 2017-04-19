#include <stdio.h>

void writeStringToFile(char* buff);
void readStringFromFile(char* buff);

int main()
{
	char* buff = malloc(256);
	writeStringToFile(buff);
	
	for (int i = 0; i < 256; i++)
	{
		buff[i] = "-";
	}
	
	readStringFromFile(buff);

	free(buff);
}

void writeStringToFile(char* buff)
{
	FILE* f = fopen("D:\\binary.txt", "wb");
	
	scanf("%s", buff);

	fwrite(buff, 256, 1, f);

	fclose(f);
}

void readStringFromFile(char* buff)
{
	FILE* f = fopen("D:\\binary.txt", "rb");

	fread(buff, 256, 1, f);

	printf("%s", buff);

	fclose(f);
}
