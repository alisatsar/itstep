using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace _2017._10._03_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var text = "Hello, beautiful world! I'm Alisa.";
            foreach(var str in Regex.Split(text, @"\s*[,!.\s]+\s*"))
            {
                Console.WriteLine(str);
            }

            var expression = @"(0[1-9]|[1-2][0-9]|3[0-1])[\./](0[1-9]|1[0-2])[\./]20\d\d";
            var result = Regex.IsMatch("03/10.2017", expression);

            Console.WriteLine(result);

            var exp = @"(public|private|protected)?\s+(static\s+)?\w+\s+[A-Z]\w*\(\)";
            var res = Regex.Matches("public void Method(){}", exp);

            foreach(var r in res)
            {
                Console.WriteLine(r);
            }
        }
    }
}
