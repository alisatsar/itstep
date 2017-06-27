#pragma once
#include <string>

class IOrder
{
public: 
	virtual ~IOrder() = default;

	virtual std::string GetName() = 0;
	virtual double GetCost() = 0;
};

class Pancake : public IOrder
{
public:
	std::string GetName()
	{
		return "Pancake with butter";
	}

	double GetCost()
	{
		return 0.5;
	}
};

class CheeseAndTomatoPancake : public IOrder
{
public:
	std::string GetName()
	{
		return "Pancake with cheese and tomato";
	}

	double GetCost()
	{
		return 1.5;
	}
};

class BananaPancake : public IOrder
{
public:
	std::string GetName()
	{
		return "Pancake with banana";
	}

	double GetCost()
	{
		return 1.0;
	}
};

class StrawberryPancake : public IOrder
{
	std::string GetName()
	{
		return "Pancake with strawberry";
	}

	double GetCost()
	{
		return 1.2;
	}
};

class Suppliment : public IOrder
{
private:
	IOrder* m_decorate;
	double m_cost;
	std::string m_name;
	size_t m_count = 0;
public:
	Suppliment(IOrder* decorate, double cost, std::string name, size_t count) :
		m_decorate(decorate), m_cost(cost), m_name(name), m_count(count)
	{
	}

	~Suppliment()
	{
		delete m_decorate;
	}

	double GetCost()
	{
		return m_decorate->GetCost() + m_cost * m_count;
	}

	std::string GetName()
	{
		std::string str = m_decorate->GetName() + m_name;
		if (m_count > 1)
		{
			str += "*" + std::to_string(m_count);
		}
		return str;
	}
};

class BaconSup : public Suppliment
{
public:
	BaconSup(IOrder* decorate, size_t count) :
		Suppliment(decorate, 0.4, "Bacon", count)
	{
	}
};

class OnionSup : public Suppliment
{
public:
	OnionSup(IOrder* decorate, size_t count) :
		Suppliment(decorate, 0.2, "Onion", count)
	{
	}
};

class ChocolateSup : public Suppliment
{
public:
	ChocolateSup(IOrder* decorate, size_t count) :
		Suppliment(decorate, 0.8, "Chocoloate", count)
	{
	}
};

class Discount : public IOrder
{
	IOrder* m_decorate;
public:
	Discount(IOrder* order) : m_decorate(order)
	{
	}

	double GetCost()
	{
		double cost = m_decorate->GetCost();
		if (cost >= 3.0)
		{
			cost *= 0.9;
		}
		return cost;
	}

	std::string GetName()
	{
		std::string str = m_decorate->GetName();
		if (m_decorate->GetCost() >= 3.0)
		{
			str += "(Discount: 10%)";
		}
		return str;
	}
};
