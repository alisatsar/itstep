#include "my_math.h"
#include <iostream>


int main()
{
	math::vector v(1.0, 2.0);

	math::matrix m(v);
	m.print();

	v = m * v;
	std::cout << v.x;
	std::cout << v.y;

	m.print();

	math::triangle t1;

	t1.vert[0].vec.x = -0.2;
	t1.vert[0].vec.y = -0.2;
	t1.vert[0].text_vec.x = 0.0;
	t1.vert[0].text_vec.y = 0.0;
	t1.vert[1].vec.x = 0.2;
	t1.vert[1].vec.y = -0.2;
	t1.vert[1].text_vec.x = 0.2;
	t1.vert[1].text_vec.y = 0.0;
	t1.vert[2].vec.x = 0.2;
	t1.vert[2].vec.y = 0.2;
	t1.vert[2].text_vec.x = 0.2;
	t1.vert[2].text_vec.y = 0.2;

	math::triangle t2;

	t2.vert[0].vec.x = 0.2;
	t2.vert[0].vec.y = 0.2;
	t2.vert[0].text_vec.x = 0.2;
	t2.vert[0].text_vec.y = 0.2;
	t2.vert[1].vec.x = -0.2;
	t2.vert[1].vec.y = 0.2;
	t2.vert[1].text_vec.x = 0.0;
	t2.vert[1].text_vec.y = 0.2;
	t2.vert[2].vec.x = -0.2;
	t2.vert[2].vec.y = -0.2;
	t2.vert[2].text_vec.x = 0.0;
	t2.vert[2].text_vec.y = 0.0;

	t1 = t1 * 2.0f;
	t1 = t1 + v;
}
