using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Threading;
using System.Collections.Concurrent;

namespace _2017._10._11
{
    class Program
    {
        /*private static ConcurrentQueue<string> list = new ConcurrentQueue<string>();

        public static void AddWork()
        {
            while(true)
            {
                list.Enqueue(Guid.NewGuid().ToString());
                Thread.Sleep(100);
            }            
        }

        public static void RemoveWork()
        {
            while(true)
            {
                string result;
                if(list.TryDequeue(out result))
                {
                    Console.WriteLine(result);
                }                
                Thread.Sleep(200);
            }            
        }
        private static void DoWork()
        {
            int i = 0;
            while(i < 10)
            {
                var currentThread = Thread.CurrentThread;
                Console.WriteLine($"Hello {currentThread.ManagedThreadId}");
                Thread.Sleep(1000);
                i++;
            }           
        }*/
        static void Main(string[] args)
        {
            //var procNotepad = Process.Start("notepad.exe");
            //var procCalc = Process.Start("calc.exe");
            //var procTxt = Process.Start("test.txt");
            //var procSite = Process.Start("http://tut.by");

            //Thread.Sleep(1000);

            //procNotepad.Kill();
            //procCalc.Kill();

            /*var thread = new Thread(new ThreadStart(DoWork));
            thread.Start();
            Thread.Sleep(500);
            thread = new Thread(new ThreadStart(DoWork));
            thread.Start();
            Console.WriteLine("Threads started");
            thread.Join(5000);
            Console.WriteLine("Threads started");
            thread.Abort();

            var task = new Task(() => Console.WriteLine("lsjflsf"));
            Task.Factory.StartNew(DoWork);

            task.Start();
            task.ContinueWith(t => DoWork());

            */

            //Task.Factory.StartNew(AddWork);

            //Task.Factory.StartNew(RemoveWork);
            //Task.Factory.StartNew(RemoveWork);
            //Task.Factory.StartNew(RemoveWork);

            var keyInfo = Console.ReadKey();
            var speedMul = keyInfo.Modifiers.HasFlag(ConsoleModifiers.Shift) ? 3 : 1;
            var heightMul = keyInfo.Modifiers.HasFlag(ConsoleModifiers.Shift) ? 5 : 1;
            switch (keyInfo.Key)
            {
                case ConsoleKey.UpArrow:
                    Console.WriteLine(50 * speedMul);
                    break;
                case ConsoleKey.DownArrow:
                    Console.WriteLine(50 * heightMul);
                    break;

            }
            

            Thread.Sleep(Timeout.Infinite);

        }
    }
}
