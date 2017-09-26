using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._26
{
    class Program
    {
        static void Main(string[] args)
        {
            Func<double, double, double> oper = Math.Min;//ПЕРвые 2 получаемые значения, последнее возвращающее
            MathOperation op = Math.Min;

            Console.WriteLine(op(10, 30));

            op += Math.Max;

            Console.WriteLine(op(10, 40));
            Console.WriteLine(op.Invoke(10, 32));

            op += Math.Log;
            
            op = (MathOperation)Delegate.Combine(op, (MathOperation)Math.Log);//равносильно op += Math.Log;

            foreach (var i in op.GetInvocationList())
            {
                Console.WriteLine(i.DynamicInvoke(10, 30));
            }


            Action<string[]> action = Main;//переполнение стекаъъ
            //action(null);

            Predicate<double> predicate = delegate(double d) { return d > 0; };//предикат возвращает bool

            Predicate<double> predicate2 = d => d > 0;//параметр входной, ЛЯмбда стрелочка => возвращаемое значение d > 0

            Console.WriteLine(predicate2(-1));

            Lesson lesson = new Lesson();
            lesson.LessonStarted += lesson_LessonStarted;

            lesson.LessonStarted += x => false;

            lesson.LessonStarted += x => x.Contains("пожалуйста");

            lesson.OnStarted();

            lesson.LessonFinished += lesson_Finishel;

            lesson.LessonFinished += (object sender, LessonEventArgs e) => e.AcceptedCount++;

            lesson.OnFinished();
            
        }

        private static void lesson_Finishel(object sender, LessonEventArgs e)
        {
            e.AcceptedCount++;
        }

        private static bool lesson_LessonStarted(string obj)
        {
            return true;
        }
    }
}
