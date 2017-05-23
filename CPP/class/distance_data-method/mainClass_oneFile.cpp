#include <iostream>

class Distance
{
private:		//модификаторы доступа, можно обращаться только из класса, нет доступа из майна
	int m_feet;			//данные класса
	float m_inches;		//класс по умолчанию Private

public:					//методы для работы с данными
	int GetFeet()
	{
		return m_feet;
	};
	float GetInches()
	{
		return m_inches;
	};
	void SetData(int feet, float inches)
	{
		m_feet = feet;
		m_inches = inches;
	};
	void Write()
	{
		std::cin >> m_feet >> m_inches;
	};
	void Print()
	{
		std::cout << m_feet << "\'" << m_inches << "\"" << std::endl;
	};
};

int main()
{
	Distance d1;

	d1.Write();
	d1.SetData(5, 6.5);
	d1.Print();

	d1.Write();
	d1.Print();

	return 0;
}
