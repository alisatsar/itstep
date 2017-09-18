using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._14
{
    class Program
    {
        static void Main(string[] args)
        {
            var student = new Student("Alisa");
            string name = "Alisa";
            //student.i = 0; нельзя, так как переменная объявлена в классе Student private

            //student.a = 2; нельзя, так как a const

            //student.str = " ";


            student.SayHello(name, student);
            student.SayBye();

            string answer = student.Answer("Where are you?");

            Console.WriteLine(answer);

            var student2 = new Student("Hanna");

            student.MethodThis();

            string answer2 = null;
            if (student.TryAnswer(ref answer2))
            {
                Console.WriteLine(answer2);
            }

            string answer3;

            if (student.TryAnswer2(out answer3))
            {
                Console.WriteLine(answer3);
            }

            student.SayHi("Alisa");

            student.SayHi("Alisa", "Karnachic");

            student.Sleep(6);
        }
    }
}
