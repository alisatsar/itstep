#include "Graphics.h"
#include "Shape.h"

#include <list>

void DrawShapes(std::list<Shape*> const& shapes, Graphics* g)
{
	for (Shape* shape : shapes)
	{
		shape->Draw(g);
	}
}

int main()
{
	Graphics g(50, 30);

	/*g.DrawEllipse(1, 1, 20, 6);
	g.DrawRectangle(5, 5, 20, 5);
	g.DrawLine(1, 1, 20, 10);*/

	Circle c1(10, 10, 5);
	Smile s1(15, 15, 10);

	//s1.Draw(&g);

	//s1.Move(22, 0);

	//s1.Draw(&g);

	Triangle t1(10, 2, 2, 10, 20, 10);
	//t1.Draw(&g);
	Triangle t2(10, 10, 2, 2, 20, 2);
	t2.Move(0, 3);
	//t2.Draw(&g);

	std::list<Shape*> list;
	list.push_back(&t1);
	list.push_back(&t2);
	list.push_back(&c1);
	list.push_back(&s1);

	DrawShapes(list, &g);

	return 0;
}
