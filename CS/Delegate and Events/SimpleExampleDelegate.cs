using System;

namespace Deleg
{
    public delegate int Transformer(int x);
    class U1
    {
        public static void Transform(int[] values, Transformer t)
        {
            for (int i = 0; i < values.Length; i++)
            {
                values[i] = t(values[i]);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int[] values = { 1, 3, 4 };
            U1.Transform(values, Square);

            foreach(int i in values)
            {
                Console.WriteLine(i + " ");
            }
        }
        static int Square(int x) => x * x;
    }    
}
