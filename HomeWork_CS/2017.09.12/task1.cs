using System;

namespace _2017._09._12_HomeWord_task1
{
    class Program
    {
        static void Main(string[] args)
        {
            var key = Console.ReadKey();

            int count = 0;
            
            while (key.Key != ConsoleKey.OemPeriod)
            {
                
                if (key.Key == ConsoleKey.Spacebar)
                {
                    ++count;
                }
                key = Console.ReadKey();
            }

            Console.WriteLine(count);
        }
    }
}
