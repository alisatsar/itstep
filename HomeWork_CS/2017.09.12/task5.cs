using System;

namespace _2017._09._12_HomeWork_task5
{
    class Program
    {
        static void Main(string[] args)
        {
            string numberStr;
            
            int numberInt;

            do
            {
                Console.WriteLine("Enter a number from 1 to 100000:");
                numberStr = Console.ReadLine();

                numberInt = int.Parse(numberStr);
            } while (numberInt <= 0 || numberInt >= 100001);

            int a = 10;
            int b = 1;

            for (int i = 0; i < numberStr.Length; i++)
            {
                Console.Write((numberInt % a) / b);
                a *= 10;
                b *= 10;
            }
            Console.Write("\n");
        }
    }
}
