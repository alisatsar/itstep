using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._10._02
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(GC.GetTotalMemory(false));
            var garbage = new Garbage();
            Console.WriteLine(GC.GetTotalMemory(false));
            var garbage2 = new Garbage();
            Console.WriteLine(GC.GetGeneration(garbage2));
            Console.WriteLine(GC.GetTotalMemory(false));
            garbage = null;
            Console.WriteLine(GC.GetTotalMemory(false));

            GC.Collect(2);//сделай сборку мусара во втором поколении

            GC.WaitForPendingFinalizers();
            Console.WriteLine(GC.GetTotalMemory(false));
            GC.KeepAlive(garbage);

            WeakReference reference = new WeakReference(garbage2);//ссылка на объект, но сборщик мусора ее за ссылку не считает

            reference.Target.ToString();
            garbage2 = null;
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();

            Console.WriteLine(GC.GetTotalMemory(false));
            Console.WriteLine(reference.IsAlive);

            Garbage garbage3 = null;

            try
            {
                garbage3 = new Garbage();
            }
            finally
            {
                if (garbage3 != null)
                {
                    garbage3.Dispose();
                }                
            }

            using(var garbage4 = new Garbage())
            {

            }
            
        }
    }
}
