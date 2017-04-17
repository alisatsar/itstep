#include <stdbool.h>

int main()
{
	FILE* file = fopen("D:\\hello.txt", "w");

	//fseek(file, 50, SEEK_SET);

	char* buff = malloc(256);
	
	for (int i = 0; i < 1024 * 1024 * 1024  / 256; i++)
	{
		fputs(buff, file);
	}
		
	fclose(file);
}

a = 1;
char str[5];
sprintf(str, "%d", a); //пишет в строку
