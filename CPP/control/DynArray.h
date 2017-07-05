#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

class Operation
{
protected:
	std::string m_name;

public:
	Operation(std::string name) : m_name(name)
	{
	}

	std::string GetName()
	{
		return m_name;
	}

	virtual void Execute() = 0;
};

class SummOperation : public Operation
{
	float m_leftOperand;
	float m_rigthOperand;
public:
	SummOperation(float leftOperand, float rigthOperand) :
		m_leftOperand(leftOperand),
		m_rigthOperand(rigthOperand),
		Operation("Summ operation")
	{
	}

	void Execute()
	{
		std::cout << m_leftOperand + m_rigthOperand;
	}
};

class DifferenceOperation : public Operation
{
	float m_leftOperand;
	float m_rigthOperand;
public:
	DifferenceOperation(float leftOperand, float rigthOperand) :
		m_leftOperand(leftOperand),
		m_rigthOperand(rigthOperand),
		Operation("Difference operation")
	{
	}

	void Execute()
	{
		std::cout << m_leftOperand - m_rigthOperand;
	}
};

class MultiplyOperation : public Operation
{
	float m_leftOperand;
	float m_rigthOperand;
public:
	MultiplyOperation(float leftOperand, float rigthOperand) :
		m_leftOperand(leftOperand),
		m_rigthOperand(rigthOperand),
		Operation("Multiply operation")
	{
	}

	void Execute()
	{
		std::cout << m_leftOperand * m_rigthOperand;
	}
};

class DivedeOperation : public Operation
{
	float m_leftOperand;
	float m_rigthOperand;
public:
	class Exception
	{
	};

	DivedeOperation(float leftOperand, float rigthOperand) :
		m_leftOperand(leftOperand),
		m_rigthOperand(rigthOperand),
		Operation("Divide operation")
	{
	}

	void Execute()
	{
		if (m_rigthOperand == 0)
		{
			throw Exception();
		}

		std::cout << m_leftOperand / m_rigthOperand;
	}
};

class ExponentOperation : public Operation
{
	const float m_e = 2.71828;
	float m_degree;
public:
	ExponentOperation(float degree) :
		m_degree(degree),
		Operation("Exponent operation")
	{
	}

	void Execute()
	{
		std::cout << pow(m_e, m_degree);
	}
};

class SinusOperation : public Operation
{
	float m_operand;
public:
	SinusOperation(float operand) :
		m_operand(operand),
		Operation("Sinus operation")
	{
	}

	void Execute()
	{
		std::cout << sin(m_operand);
	}
};

class CosineOperation : public Operation
{
	float m_operand;
public:
	CosineOperation(float operand) :
		m_operand(operand),
		Operation("Cosine operation")
	{
	}

	void Execute()
	{
		std::cout << cos(m_operand);
	}
};

class Calculator
{
	std::vector<Operation*> m_operations;
public:
	Calculator(Operation* operations)
	{
		m_operations.push_back(operations);
	}

	void ShowMenu()
	{
		std::vector<Operation*>::iterator it;
		it = m_operations.begin();
		while (it != m_operations.end())
		{
			std::cout << (*it)->GetName();
		}
	}


};
