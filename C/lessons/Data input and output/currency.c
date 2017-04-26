#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Currency
{
	float BYNtoUSD;
	float USDtoBYN;
	float BYNtoEUR;
	float EURtoBYN;
};

int main()
{
	struct Currency* currency = malloc(sizeof(struct Currency));
	FILE* file = fopen("d:\\db.bin", "rb");
	struct Currency buff;
	
	if (file == NULL)
	{
		FILE* file = fopen("d:\\db.bin", "wb");
		currency->BYNtoUSD = 1.87;
		currency->USDtoBYN = 1.8810;
		currency->BYNtoEUR = 2.0040;
		currency->EURtoBYN = 2.02;
		fwrite(currency, sizeof(struct Currency), 1, file);
	}
	else
	{
		fseek(file, 0, SEEK_SET);
		fread(&buff, sizeof(struct Currency), 1, file);
		printf("BYN to USD: %.2f\n", buff.BYNtoUSD);
		printf("USD to BYN: %.2f\n", buff.USDtoBYN);
		printf("BYN to EUR: %.2f\n", buff.BYNtoEUR);
		printf("EUR to BYN: %.2f\n", buff.EURtoBYN);
	}
		
	fclose(file);
}
