using System;

namespace _2017._09._12_HomeWork_task4
{
    class Program
    {
        static void Main(string[] args)
        {
            string beginNumberStr;
            string endNumberStr;

            int beginNumberInt;
            int endNumberInt;

            do
            {
                Console.WriteLine("Enter a number from 1 to 9 that you want to start");
                beginNumberStr = Console.ReadLine();

                beginNumberInt = int.Parse(beginNumberStr);
            } while (beginNumberInt <= 0 || beginNumberInt >= 10);

            do
            {
                Console.Write("Enter a number from ");
                Console.Write(beginNumberInt + 1);
                Console.WriteLine(" to 9 that you want to end");

                endNumberStr = Console.ReadLine();

                endNumberInt = int.Parse(endNumberStr);
            } while (endNumberInt <= beginNumberInt || endNumberInt > 10);

            for(int i = 0; i < beginNumberInt; i++)
            {
                for (int j = 0; j < beginNumberInt; j++)
                {
                    Console.Write(beginNumberInt);
                    Console.Write(" ");
                }
                Console.Write("\n");
                if (beginNumberInt == endNumberInt)
                {
                    break;
                }
                ++beginNumberInt;
            }
        }
    }
}
