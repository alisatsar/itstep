using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace _2017._09._26
{
    class Program
    {
        static void Main(string[] args)
        {
            var array = new SmartArray();
            array.Add(0);
            array.Add(3);
            array.Add(-3);
            array.Add(100);

            //array = array.Where(x => x > 0).Where(x => x < 0);

            array = array.Select(x => x * x);

            array.Print();

            Console.WriteLine(array.Where(x => x < 100).Count(x => x > 0));
        }

        
    }
}
