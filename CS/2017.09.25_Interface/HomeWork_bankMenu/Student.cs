using System;

namespace _2017._09._25_2
{
    public class Student : Human
    {
        public Student()
            : base("Undefined")
        {
            Console.WriteLine("Student.");
        }

        public override void Print()
        {
            throw new NotImplementedException();
        }

        public override void SayHello()
        {
            Console.WriteLine("Hello from student!");
        }
    }
}