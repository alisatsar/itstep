using System;

namespace _2017._09._25_2
{
    public class Teacher : Human
    {
        public Teacher()
            : base("Undefined")
        {
            Console.WriteLine("Teacher.");
        }

        public override void Print()
        {
            throw new NotImplementedException();
        }

        public override void SayHello()
        {
            Console.WriteLine("Hello from teacher!");
        }
    }
}
