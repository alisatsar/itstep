using System;

namespace Deleg
{
    public delegate void ProgresReporter(int percentComplete);

    public class X
    {
        public void InstanceProgress(int percentComplete) => Console.WriteLine(percentComplete);
    }
    class Program
    {
        static void Main(string[] args)
        {
            X x = new X();
            ProgresReporter p = x.InstanceProgress;
            p(99);
            Console.WriteLine(p.Target == x);
            Console.WriteLine(p.Method);
        }
    }    
}
