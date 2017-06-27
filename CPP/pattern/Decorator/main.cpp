#include "IOrder.h"
#include <iostream>

enum Sup
{
	Bacon,
	Onion,
	Chocolate
};

IOrder* AddSupplicion(IOrder* order, Sup sup, size_t count)
{
	switch (sup)
	{
	case Bacon:
		return new BaconSup(order, count);
	case Onion:
		return new OnionSup(order, count);
	case Chocolate:
		return new ChocolateSup(order, count);
	default:
		return order;
	}
}

void PrintOrder(IOrder* order)
{
	std::cout << "Order: " << order->GetName() << "\n"
		<< "Cost: " << order->GetCost() << std::endl;
}

IOrder* AddDiscount(IOrder* order)
{
	return new Discount(order);
}

int main()
{
	IOrder* order;

	order = new Pancake;
	
	order = AddSupplicion(order, Bacon, 10);

	order = AddDiscount(order);

	PrintOrder(order);

	return 0;
}
