using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._26
{
    public class ResultEventAgs : EventArgs
    {
        public double Result { get; private set; }

        public ResultEventAgs(double result)
        {
            Result = result;
        }
    }
    
    public class SmartArray
    {
        private List<int> array = new List<int>();

        public void Add(int i)
        {
            array.Add(i);
        }

        public SmartArray Where(Predicate<int> predicate)
        {
            var result = new SmartArray();

            foreach(var i in array)
            {
                if (predicate(i))
                {
                    result.Add(i);
                }
            }

            return result;
        }

        public SmartArray Select(Func<int , int> func)
        {
            var result = new SmartArray();

            foreach(var i in array)
            {
                result.Add(func(i));
            }

            return result;
        }

        public void Print()
        {
            foreach(var i in array)
            {
                Console.WriteLine(string.Join(" " , array));;
            }
            
        }

        public int Count(Predicate<int> predicate)
        {
            int result = 0;

            foreach (var i in array)
            {
                if (predicate(i))
                {
                    ++result;
                }
            }

            return result;
        }

    }
}
