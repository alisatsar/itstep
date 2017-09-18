using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._18_2
{
    public class Student
    {
        private int mark;
        private int[] marks = new int[100];
        
        public int Mark
        {
            get {return mark; }
            set
            {
                mark = Math.Min(12, Math.Max(0, value));
            }
        }

        public double AverageMark
        {
            get
            {
                return marks.Average();
            }
        }

        public bool WanOnLesson
        {
            get
            {
                return Pres != Presence.Absent;
            }
        }

        public Presence Pres { get; set; }
        
    }
}
