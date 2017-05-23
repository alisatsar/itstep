#include "distance.h"
#include <iostream>

int main()
{
	/*Distance d1;
	d1.Read();

	Distance d2;
	d2.Read();
	d1.Add(d2);
	d1.Print();

	d1.Read();
	d2.Read();
	d1.Deduct(d2);
	d1.Print();


	Distance* d3 = new Distance();
	d3->SetData(4, 4.5);
	d3->Print();
	delete d3;*/

	Distance* array = new Distance[5];
	for (int i = 0; i < 5; i++)
	{
		array[i].Read();
	}

	Distance result;
	result.SetData(0, 0);

	for (int i = 0; i < 5; i++)
	{
		result.Add(array[i]);
	}

	result.Print();
	delete[] array;

	return 0;
}
