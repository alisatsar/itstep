#include <stdio.h>
#include <stdlib.h>

#define SIZE_LIST 5

char* myCAlloc(int blockCount, int blockSize)
{
	char* c = malloc(blockCount * blockSize);

	for (int i = 0; i < blockCount * blockSize; i++)
	{
		c[i] = 0;
	}
}


int main()
{
	char* elements = calloc(SIZE_LIST, sizeof(char*));
	
	
}
