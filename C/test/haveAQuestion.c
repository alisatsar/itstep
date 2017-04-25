#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ch;		//переменная int для хранения EOF (что достигнут конец файла)
	FILE* file;
	unsigned long count = 0;

	if (argc != 2)
	{
		printf("Use: %s file name\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((file = fopen(argv[1], "r")) == NULL)
	{
		printf("File has not open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(file)) != EOF) //получить символ из файла, идентифицируемого file
	{
		putc(ch, stdout); //сначала задается символ, а затем указатель файла
		count++;
	}
	fclose(file);		// возвращает значение 0, если файл был закрыт успешно и EOF, если нет

	printf("File %s contain %lu character\n", argv[1], count);

	return 0;
}
