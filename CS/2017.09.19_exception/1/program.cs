using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19
{
    class Program
    {
        static void Main(string[] args)
        {
            var shop = new Shop();
            shop.AddLaptop(new Laptop()
            {
                Brand = "Dell",
                Price = 12.8m
            });

            if (shop[100] != null)
            {
                Console.WriteLine(shop[1].Brand);
            }
            
            var laptopsBrandDell = shop["Dell"];

            foreach(var laptop in shop["Dell"])
            {
                Console.WriteLine("{0}:{1}", laptop.Brand, laptop.Price);
            }


        }
        
    }
}
