using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19
{
    public class SmartArray
    {
        private int[] array;

        public SmartArray(int count)
        {
            array = new int[count];

        }

        public int this[int i]
        {
            get
            {
                if (i < 0)
                {
                    i = array.Length + i;
                }
                if (i > 0 && i < array.Length)
                {
                    return this[i];
                }

                throw new ArgumentOutOfRangeException();
                
            }
        }
    }
}
