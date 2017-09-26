using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._26
{
    public class LessonEventArgs : EventArgs
    {
        public string HomeWork { get; set; }

        public int AcceptedCount { get; set; }
    }

    public class Lesson
    {
        public event Predicate<string> LessonStarted;//называется тем, что сейчас происходит глагол

        private EventHandler<LessonEventArgs> finished;
        public event EventHandler<LessonEventArgs> LessonFinished
        {
            add
            {
                finished += value;
            }
            remove
            {
                finished -= value;
            }
        }

        public  void OnStarted()
        {
            Predicate<string> hadler = LessonStarted;

            if (hadler != null)
            {
                int count = 0;
                foreach (Predicate<string> predicate in hadler.GetInvocationList())
                {
                    if (hadler("Идите на занятия, пожалнйста"))
                    {
                        count++;
                    }
                }
                Console.WriteLine("{0} Студенты идут на занятия, пожалуйста", count);
                
            }
        }

        public void OnFinished()
        {
            var handler = finished;
            if (handler != null)
            {
                var args = new LessonEventArgs()
                {
                    HomeWork = "Читай Рихтера, пожалуйста!"
                };

                handler(this, args);
                Console.WriteLine("{0} студентов сделают ", args.AcceptedCount);
            }
        }
    }
}
