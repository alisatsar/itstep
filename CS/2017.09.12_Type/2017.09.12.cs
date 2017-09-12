using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._12_CS
{
    enum WeekDay
    {
        Monday = 1,
        Thuesday
    };
    class Program
    {
        static void Main(string[] args)
        {
            /*byte b = 10;

            Console.WriteLine(b.GetType().Name);

            Console.Read();

            decimal dec = 0.1m;
            dec = dec / 3;

            Console.WriteLine(dec);

            dec = dec * 3;

            Console.WriteLine(dec);
            
            //Char.
            //Math.

            int? a = null;// Nullable<T>

            Console.WriteLine(WeekDay.Thuesday);

            var i = 10;

            var name = new { Name = "Alisa" };

            int integ = 10;

            float f = 12;

            float x = integ * f;

            //Convert.

            Int32.Parse("123455");

            //Console.WriteLine(nameof(integ)); Новое, зависит от версии framework и языка

            Console.WriteLine(typeof(Int32));

            Console.WriteLine(default(int?));*/


            int x = 0;
            int y = 0;

            var key = Console.ReadKey();

            Console.WriteLine("@");

            var random = new Random();

            int boneX = random.Next(0, Console.WindowWidth - 1);

            int boneY = random.Next(0, Console.BufferHeight);

            while (key.Key != ConsoleKey.Escape)
            {
               
                switch(key.Key)
                {
                    case ConsoleKey.UpArrow:
                        y = y > 0 ? y - 1 : 0;
                        break;
                    case ConsoleKey.DownArrow:
                        y = y < Console.BufferHeight ? y + 1 : Console.BufferHeight;
                        break;
                    case ConsoleKey.LeftArrow:
                        x = x > 0 ? x - 1 : 0;
                        break;
                    case ConsoleKey.RightArrow:
                        x = x < Console.BufferWidth - 1 ? x + 1 : Console.BufferWidth - 1;
                        break;
                }

                Console.Clear();
                Console.SetCursorPosition(x, y);
                Console.Write("@");

                Console.SetCursorPosition(boneX, boneY);
                Console.Write("x"); 
               
                if (x == boneX && y == boneY)
                {
                    boneX = random.Next(0, Console.WindowWidth - 1);
                    boneY = random.Next(0, Console.BufferHeight);
                }

                key = Console.ReadKey();
            }
           
        }
    }
}
