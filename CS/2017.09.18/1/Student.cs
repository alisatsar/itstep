using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._18
{
    public class Student
    {  
        //propfull +tab + tab автоматически генерирует запись
        private int myVar;
        public int MyProperty
        {
            get { return myVar; }
            set { myVar = value; }
        }
        private string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public string Normal
        {
            get { return name.ToUpper(); }
        }

        public string SecondName { get; set; }

        public void SetMethod()
        {
            SecondName = "Tsarova";
        }
            
      
    }
}
