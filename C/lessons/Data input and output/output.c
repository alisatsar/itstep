//#include <stdio.h>
//
//int main()
//{
//	FILE* file = fopen("C:\\Windows\\system.ini", "r");
//
//	char* buff = malloc(1024);
//
//	while (fgets(buff, 1024, file))
//	{
//		printf("%s", buff);
//	}
//		
//	fclose(file);
//}

//#include <stdio.h>
//
//int main()
//{
//	FILE* file = fopen("C:\\Windows\\system.ini", "r");
//
//	fseek(file, -25, SEEK_END);
//
//	char* buff = malloc(1024);
//
//	while (fgets(buff, 1024, file))
//	{
//		printf("%s", buff);
//	}
//
//	fclose(file);
//}

#include <stdio.h>

int main()
{
	FILE* file = fopen("C:\\Windows\\system.ini", "r");

	fseek(file, 50, SEEK_SET);

	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);

	char* buff = malloc(256);
	long position = ftell(file);
	printf("Pos: %i", position);

	while (fgets(buff, 256, file))
	{
		fseek(file, -50, SEEK_CUR);
		position = ftell(file);
		printf("Pos: %i", position);
		printf("%s", buff);
	}

	fclose(file);
}
