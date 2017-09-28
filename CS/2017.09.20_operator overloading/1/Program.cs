using _2017._09._20.Buttons;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using WPF = _2017._09._20.Wpf;
using WpfButton = _2017._09._20.Wpf.Button;
//using static System.Math;//от версии 6.0

namespace _2017._09._20
{
    class Program
    {
        static void Main(string[] args)
        {
            //var button = new Buttons.Button();
            //var button = new WPF.Button();

            var button = new WpfButton();

            /*var p1 = new Point()
            {
                xPos = 10,
                yPos = 1
            };*/

            //Console.WriteLine(p1++);
            //Console.WriteLine(++p1);
            //Console.WriteLine(--p1);
            //Console.WriteLine(-p1);

            var v1 = new Vector(new Point(1, 1), new Point(3, 5));
            var v2 = new Vector(new Point(3.3f, 6.6f), new Point(-1.1f, -19));

            Console.WriteLine(v1 + v2);
            Console.WriteLine(v1 * 5);

            var p1 = new Point(1, 1);
            var p2 = new Point(1, 1);

            Console.WriteLine(p1.Equals(p2));
            Console.WriteLine(ReferenceEquals(p1, p2));


            var pStruct1 = new PointStruct(1, 1);
            var pStruct2 = new PointStruct(1, 1);

            Console.WriteLine(pStruct1.Equals(pStruct2));
            Console.WriteLine(ReferenceEquals(pStruct1, pStruct2));

            Console.WriteLine(v1.Equals(v2));

            Console.WriteLine(v1 > v2);
            Console.WriteLine(v1 < v2);
        
        }
    }
}
