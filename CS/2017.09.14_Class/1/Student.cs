using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._14
{
    public partial class Student
    {
        private int i = 0;

        public const int a = 2;

        public static string str = "static";

        private static string m_name;

        public Student(string name)
        {
            //если бы имена совпадали, то this.name = name;
            m_name = name;
        }
        public Student(string name, int age) : this(name)
        {
            i = age;
        }

        static Student()
        {
            m_name = ("This student has not name");
        }

        public void SayHello(string name, Student student)//по умолчанию name передается не по ссылке, а по копии ссылке
            //Student student можем поменять поле
        {
            name = "Sasha";
            Console.WriteLine("Hello, " +name);
        }

        public void SayBye(string name = "Bye")
        {
            Console.WriteLine(name);
        }

        public string Answer(string word)
        {
            return "I don't know";
        }

        //int GetAge1() => 15; равняется в 15

        int GetAge() 
        {
            return 15;
        }

        public void MethodThis()
        {
            Console.WriteLine(this);
        }

        public bool TryAnswer(ref string answer)
        {
            answer = "43";
            return true;
        }

        public bool TryAnswer2(out string answer)
        {
            answer = "43";
            return true;
        }

        public void SayHi(params string[] names)
        {
            Console.WriteLine("Hello " + string.Join(" ,", names));
        }
    
    }
}
