include <iostream>
#include "student.h"

void PrintMaxRaiting(Student s1, Student s2)
{
	std::cout << (s1.GetRating() < s2.GetRating() ? s2.GetRating() : s1.GetRating()) << "\n";
}

Student Create(Group& group, char const* name)
{
	Student s(group, name, 0);
	return s;
}

int main()
{
	Group g;
	Student s1(g, "Ivanov", 6);
	Student s2 = s1;	//copy constructor
	Student s3(s1);		//copy constructor
	s2.SetName("Serov");
	s2.SetRating(5);
	s1.Print();
	s2.Print();

	PrintMaxRaiting(s1, s2);	//copy constructor //copy constructor

	Create(g, "Sidorov").Print();		//copy constructor

	/*Student s4 = Create(g, "Sidorov");		//copy constructor another realization
	s4.Print();*/


	Student* pSt = new Student(g, "Ivanov", 3);
	delete pSt;


	const Student stud(g, "Ivanov", 4);
	stud.GetRating();
	stud.Print();
	return 0;
}

//int count;
//std::cin >> count;
//Student** students = new Student*[count];
//for (int i = 0; i < count; ++i)
//{
//	Student* st = new Student(g);
//	students[i] = st;
//}
//
//students[0]->
