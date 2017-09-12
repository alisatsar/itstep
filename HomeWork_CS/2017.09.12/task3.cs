using System;

namespace _2017._09._12_HomeWork_task3
{
    class Program
    {
        static void Main(string[] args)
        {
            string str;
            
            char t;

            Console.WriteLine("Enter the string:");
            str = Console.ReadLine();

            var ch = str.ToCharArray();
            
            for (int i = 0; i < str.Length; i++)
            {
                if((int)ch[i] >= 97 && (int)ch[i] <=122)
                {
                    t = (char)((int)ch[i] - 32);
                    Console.Write(t);
                }
                else
                {
                    Console.Write(ch[i]);
                }
            }
            Console.Write("\n");
        }
    }
}
