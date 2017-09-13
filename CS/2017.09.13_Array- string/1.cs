using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._13
{
    class Program
    {
        static void Main(string[] args)
        {
            /*int[] a = new int[10];

            foreach(var x in a)
            {
                x = 10;//нельзя из-за того что возвращает копию элемента
            }

            int[][] a = new int[5][];

            for (int i = 0; i < 5; i++)
            {
                a[i] = new int[i + 1];
            }

            foreach(int[] x in a)
            {
                Console.Write(x);
                foreach(int y in x)
                {
                    Console.Write(y);
                }
                Console.WriteLine();
            }

            int [,] b = new int[4,3];

            foreach(int x in b)
            {
                Console.Write(x);
            }

            int[] arr = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            Console.WriteLine(arr.Sum());

            Console.WriteLine(arr.Average());
            Console.WriteLine(arr.Max());
            Console.WriteLine(arr.Min());
            Console.WriteLine(arr.ToString());

            int z = Array.BinarySearch(arr, 5); //возвращает индекс

            Console.WriteLine(z);*/

            string s = "Get";

            s = s.ToUpper();//мзменит строку
            s.ToUpper(); //не изменит строку, а создаст новую

            string str = @"Hello\";//воспринимает строку буквально

            str = @"Hello, 
Alisa";

            Console.WriteLine(str);

            var age = 50;

            var str2 = String.Format("Hello, I'm {0} years old", age);

            Console.WriteLine(str2);

            var str3 = String.Format("i'm {1}, {0:x} years", 28, "Alisa");

            Console.WriteLine(str3);

            //var name = "Sergey";

            //Console.WriteLine($"Hello, {name}");c 6 framework

            str = str + " Hello";

            Console.WriteLine(str);

            StringBuilder sb = new StringBuilder();

            Console.WriteLine(sb.Capacity);

            sb.Append("");

            sb.ToString();

            Console.WriteLine(args[0]);
            Console.WriteLine(args[1]);
        }
    }
}
