using System;

namespace _2017._09._12_HomeWork_task2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter number (6 characters):");

            string numberStr;

            do
            {
                Console.WriteLine("The number must be the 6 characters!");
                numberStr = Console.ReadLine();
            } while (numberStr.Length != 6);

            int numberInt = int.Parse(numberStr);

            int summFirst = numberInt / 100000 + (numberInt % 100000) / 10000 + (numberInt % 10000) / 1000;

            int summSecond = numberInt % 1000 / 100 + numberInt % 100 / 10 + numberInt % 10;

            Console.WriteLine(summFirst == summSecond ? "Lucky" : "Unlucky");
        }
    }
}
