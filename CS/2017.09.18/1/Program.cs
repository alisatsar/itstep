using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._18
{
    class Program
    {
        static void Main(string[] args)
        {
            /*var point = new Point(1, 4);
            Console.WriteLine(point);

            var point1 = new PointClass(2, 5);
            Console.WriteLine(point1);

            point.SetX(20);
            point1.SetX(30);

            Console.WriteLine(point);
            Console.WriteLine(point1);

            SetXes(point, point1);

            Console.WriteLine(point);
            Console.WriteLine(point1);

            //Point point2 = null;//нельзя использовать, так как нет смысла выделять память на стеке для налл

            Point? point2 = null;//вопрос превращает в ссылку

            Nullable<Point> p3 = null;

            Console.WriteLine(point2.HasValue);

            //Console.WriteLine(point2.Value); нельзя, так как там нет значения

            if(p3 == null)
            {
                p3 = new Point(10, 10);
            }
            //равно =>    p3 = p3 ?? new Point(10, 10);

            var readWrite = Permission.ReadWrite;

            //if ((readWrite & Permission.Write) == Permission.Write){}

            Console.WriteLine(readWrite.HasFlag(Permission.Write));

            int intEnum = int.Parse("2");

            Permission result;
            var str = Console.ReadLine();

            int intValue;

            if (int.TryParse(str, out intValue))
            {
                result = (Permission)intValue;
                Console.WriteLine(result);
            }
            else
            {
                result = (Permission)Enum.Parse(typeof(Permission), str); 
                Console.WriteLine((int)result);
            }*/

            var student = new Student();
            
            student.Name = "Sergey";//нельзя если установить private

            Console.WriteLine(student.Name);

            var student2 = new Student() { SecondName = "Alisa" };

            Console.WriteLine(student2.SecondName);
            PrintStudent(null);

        }

        public static void SetXes(Point point, PointClass point1)
        {
            point.SetX(100);
            point1.SetX(200);

        }

        public static void PrintStudent(Student st)
        {
            if (st == null)
            {
                return;
            }

            Console.WriteLine(st.Name);
            //Console.WriteLine(st?.Name); //st == null ? null : st.Name 6.0 version
        }
    }
}
