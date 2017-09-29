using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25
{
    class Program
    {
        static void Main(string[] args)
        {
            IStudent student = new Student();
            Console.WriteLine(((Student)student).LastName);

            Console.WriteLine((student as Student).LastName);

            Console.WriteLine(student is IStudent);

            StudentsList list = new StudentsList();

            list.AddStudent(new Student() { Name = "Alisa" });

            list.AddStudent(new Student() { Name = "Al" });           

           

            list.AddStudent(new Student() { Name = "Alisa", BirthDate = new DateTime(1989, 3, 5) });

            list.AddStudent(new Student() { Name = "Alisa", BirthDate = new DateTime(1987, 3, 5) });

            list.SortByDate();

            foreach (Student st in list)
            {
                if (st != null)
                {
                    Console.WriteLine(st.BirthDate);
                }
            }
        }
    }
}
