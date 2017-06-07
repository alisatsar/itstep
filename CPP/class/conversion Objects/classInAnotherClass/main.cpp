#include "example.h"
#include <iostream>

int main()
{
	Time12 t12(true, 12, 2);

	t12.Show();

	Time24 t24(2, 6, 59);

	///////////////////////////
	t12 = t24;	//преобразовать time24 - time12
	///////////////////////////

	t24.Show();
	t12.Show();

	return 0;
}
