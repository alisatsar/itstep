#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define FILE_SIZE 170
#define STRING_SIZE 50

enum StringPositions
{
	FirstNamePosition = 0,
	LastNamePosition = 57,
	MiddleNamePosition = 119,
};

void writeString(char* string, int offset, FILE* f)
{
	fseek(f, offset, SEEK_SET);	//перемещение идентификатора(файл; на сколько переместиться; аргумент в fseek(),
 //обозначающий отсчёт с начала файла)
	fwrite(string, STRING_SIZE, 1, f);			//пишем строку в файл
}

void readString(char* string, int offset, FILE* f)
{
	fseek(f, offset, SEEK_SET);
	fread(string, STRING_SIZE, 1, f);
}

int main()
{
	setlocale(LC_ALL, "rus");
	FILE* f = fopen("d:\\t.bin", "rb");		//Открыть файл для чтения в бинарном режиме
	char* buff = malloc(FILE_SIZE);			//создаем буффур  размером с файл

	if (f == NULL)							// если файл пуст, то нужно записать
	{
		// need to write
		f = fopen("d:\\t.bin", "wb");	//открываем в режиме записи
		memset(buff, 0, FILE_SIZE);	//заполняем буффер нулями (указатель на объект для заполнения/заполнить байт/количество
  //байт для заполнения)
		fwrite(buff, FILE_SIZE, 1, f);	//пишет 1 объект в заданном массиве buff к файлу f (FILE_SIZE - размер объекта,
//который надо записать)

		strcpy(buff, "Alisa");			//копируем из "Alisa" в буффер
		writeString(buff, FirstNamePosition, f);	//передаем строку byff, позицию заданную в enum, и указатель на файл
		strcpy(buff, "Tsarova");
		writeString(buff, LastNamePosition,	f);
		strcpy(buff, "Aleksandrovna");
		writeString(buff, MiddleNamePosition, f);
	}
	else
	{
		// need to read
		readString(buff, FirstNamePosition, f);
		printf("FirstName: %s\n", buff);
		readString(buff, LastNamePosition, f);
		printf("LastName: %s\n", buff);
		readString(buff, MiddleNamePosition, f);
		printf("MiddleName: %s\n", buff);

	}

	fclose(f);
}
