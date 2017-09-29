using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25
{
    public class BirthDateComparer : IComparer
    {
        public int Compare(object x, object y)
        {
            if (x == null)
            {
                return 1;
            }
            if (y == null)
            {
                return -1;
            }
            return DateTime.Compare(((Student)x).BirthDate, ((Student)y).BirthDate);
        }
    }
}
