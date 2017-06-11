#include "Array.h"

int main()
{
  Array<int, 11> array11;

	for (int i = 0; i < array11.GetSize(); i++)
	{
		array11[i] = i + 1;
	}

	/*Array<double, 10> array10 = array11;
	for (int i = 0; i < array10.GetSize(); i++)
	{
		std::cout << array10[i] << " ";
	}*/

	Array<int, 10> array10;

	array10 = array11;

	for (int i = 0; i < array10.GetSize(); i++)
	{
		std::cout << array10[i] << " ";
	}

	return 0;
  
}  
