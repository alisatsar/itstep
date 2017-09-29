using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25
{
    public class Student : IStudent, IComparable
    {
        public string LastName { get; set; }
        public string Name { get; set; }
        public DateTime BirthDate { get; set; }
       
        public string this[int i]
        {
            get
            {
                throw new NotImplementedException();
            }
            set
            {
                throw new NotImplementedException();
            }
        }

        public int CompareTo(object obj)
        {
            if (obj == null)
            {
                return -1;
            }
            
            var s = obj as Student;
            if (s != null)
            {
                return Name.CompareTo(s.Name);
            }

            throw new NotSupportedException();
        }
    }
}
