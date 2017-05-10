#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	WIN32_FIND_DATAA found;
	HANDLE findResult = FindFirstFileA("C:\\WIndows\\*", &found); //* заменяет любое количество символов 
																//? заменяет только один символ

	if (findResult == INVALID_HANDLE_VALUE)
	{
		printf("Error\n");
		return 1;
	}
	
	do
	{
		if (strcmp(found.cFileName, ".") == 0)
		{
			continue;
		}
		bool  isDirectory = found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
		if (isDirectory)
		{
			printf("D ");
		}
		else
		{
			printf("F ");
		}
		bool isArchive = found.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE;
		if (isArchive)
		{
			printf("A ");
		}
		else
		{
			printf("- ");
		}
		bool isHidden = found.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN;
		if (isHidden)
		{
			printf("H ");
		}
		else
		{
			printf("- ");
		}
		bool isCompressed = found.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED;
		if (isHidden)
		{
			printf("C ");
		}
		else
		{
			printf("- ");
		}
		bool isEncrypted = found.dwFileAttributes & FILE_ATTRIBUTE_ENCRYPTED;
		if (isEncrypted)
		{
			printf("E ");
		}
		else
		{
			printf("- ");
		}
		printf(" %s\n", found.cFileName);
			
	} while (FindNextFileA(findResult, &found));

	FindClose(findResult);
}
