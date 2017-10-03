using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace _2017._10._03_HomeWork_2
{
    class Program
    {
        static void Main(string[] args)
        {
            string buf;
            using (StreamReader sr = new StreamReader("Struct.cs"))
            {
                buf = sr.ReadToEnd();
            }            
;
            string pattern = "public+";
            string replacement = "private";
            Regex rg = new Regex(pattern);
            string res = rg.Replace(buf, replacement);

            Console.WriteLine("Original String: {0}", buf);
            Console.WriteLine("Replacement String 1: {0}", res);


            string pattern2 = @"\b[a-z][a-z]";
                                   
            string replacement2 = @"[A-z][A-z]";

            Regex rg2 = new Regex(pattern2);

            var t = rg2.Match(res, pattern);

            

            //string res2 = rg2.Replace(buf, replacement2);

            //Console.WriteLine("Replacement String 2: {0}", res2);
        }
    }
}
