#include <iostream>
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

/*int main()
{
	Group g;
	Student s1(g, "Ivanov", 6);
	Student s2 = s1;
	Student s3(s1);

	std::cout << "count = " << Student::GetStudentCount() << "\n";

	s2.SetName("Petrov");
	s2.SetRating(5);
	s1.Print();
	s2.Print();

	PrintMaxRaiting(s1, s2);
	Student* s5;
	{
		s5 = new Student(g);
		Student s4 = Create(g, "Sidorov");
		s4.Print();
		std::cout << "count = " << Student::GetStudentCount() << "\n";
	}
	std::cout << "count = " << Student::GetStudentCount() << "\n";
	delete s5;
	std::cout << "count = " << Student::GetStudentCount() << "\n";
}*/
