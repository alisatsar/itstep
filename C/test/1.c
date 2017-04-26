#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Currency
{
	float BYNtoUSD;
	float USDtoBYN;
	float BYNtoEUR;
	float EURtoBYN;
	char bankName[25];
};

int main()
{
	FILE* file = fopen("d:\\db.bin", "rb");
	struct Currency currency;

	if (file == NULL)
	{
		FILE* file = fopen("d:\\db.bin", "wb");
		currency.BYNtoUSD = 1.87;
		currency.USDtoBYN = 1.8810;
		currency.BYNtoEUR = 2.0040;
		currency.EURtoBYN = 2.02;
		fwrite(&currency, sizeof(struct Currency), 1, file);
		fclose(file);
		return 0;
	}
	else
	{
		fseek(file, 0, SEEK_SET);
		fread(currency, sizeof(struct Currency), 1, file);
		printf("BYN to USD: %.2f\n", currency->BYNtoUSD);
		printf("USD to BYN: %.2f\n", currency->USDtoBYN);
		printf("BYN to EUR: %.2f\n", currency->BYNtoEUR);
		printf("EUR to BYN: %.2f\n", currency->EURtoBYN);
	}

	fseek(file, 0, SEEK_END);
	int sizeFile = ftell(file);

	if (sizeFile != sizeof(struct Currency))
	{
		FILE* file2 = fopen("d:\\db2.bin", "wb");
		//printf("%s", currency->bankName);
		currency->BYNtoUSD = 1.87;
		currency->USDtoBYN = 1.8810;
		currency->BYNtoEUR = 2.0040;
		currency->EURtoBYN = 2.02;
		strcpy(currency->bankName, "PriorBank");
		fwrite(currency, sizeof(struct Currency), 1, file);
		fseek(file, 0, SEEK_SET);
		fread(currency, sizeof(struct Currency), 1, file);
		printf("%s\n", currency->bankName);
		fclose(file2);
	}

	fclose(file);

}
