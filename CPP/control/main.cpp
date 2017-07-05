#include "Operation.h"

int main()
{
	Operation* operation = new SummOperation(3, 3);

	operation->Execute();

	std::cout << operation->GetName() << std::endl;

	Calculator calc(operation);
}
