#include <iostream>
using namespace std;

class Distance // класс для английских мер длины
{
private:
	const float MTF;  // метры к футам     
	int feet;
	float inches;
public:   
	// конструктор без аргументов     
	Distance() : feet(0), inches(0.0), MTF(3.280833F)
	{ }

	// ЯВНЫЙ (EXPLICIT) конструктор с одним аргументом     
	explicit Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters;
		feet = int(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	///////////////////////////////////////////////////

	void showdist() // показать расстояние      
	{
		cout << feet << "\'-" << inches << '\"';
	}
};
