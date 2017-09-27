using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._27
{
    public static class StudentExtensions
    {
        public static int GetAge(this DateTime date)
        {
            return (int)((DateTime.Now - date).Days / 365.25);
        }
        public static void Print(this Student st)
        {            
            Console.WriteLine("{0} {1}, {2}", st.Name, st.Surname, st.BirthDate.GetAge());
        }

        public static void Print(this IEnumerable<Student> st)
        {
            foreach(var s in st)
            {
                s.Print();
            }            
        }
    }
}
