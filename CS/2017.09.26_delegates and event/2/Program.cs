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
            //Calculator calc = new Calculator();

            

            //calc.ResultCalculated += (o, e) => Console.WriteLine(e.Result);
            //calc.ResultCalculated += (o, e) => Console.WriteLine(e.Result);
            //calc.ResultCalculated += (o, e) => Console.WriteLine(e.Result);
            //calc.ResultCalculated += (o, e) => Console.WriteLine(e.Result);
            //calc.ResultCalculated += (o, e) => Console.WriteLine(e.Result);
            //calc.Start();
            //Console.WriteLine(calc.ResultCalculated());

            Timer timer = new Timer(1000);

            timer.Elapsed += (o, e) => { Console.Clear(); Console.WriteLine(e.SignalTime); };
            timer.Start();

            Console.ReadLine();
        }

        
    }
}
