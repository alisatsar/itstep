using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25
{
    public class StudentsList : IEnumerable
    {
        private Student[] students = new Student[20];
        private int count; 

        public void AddStudent(Student s)
        {
            students[count++] = s;
            Array.Sort(students);                       
        }

        public IEnumerator GetEnumerator()
        {
            return students.GetEnumerator();
        }    
   
        public void SortByDate()
        {
            Array.Sort(students, new BirthDateComparer());
        }
    }
}
