using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19
{
    public class Shop
    {
        private Laptop[] laptops = new Laptop[100];
        private int count = 0;

        public void AddLaptop (Laptop laptop)
        {
            laptops[count++] = laptop;
        }

        public Laptop this[int i]
        {
            get
            { 
                if( i < 0 || i >= laptops.Length)
                {
                    return null;  
                }
                return laptops[i];
            }
            set
            {
                laptops[i] = value;
            }
               
        }

        public Laptop[] this[string brand]
        {
            get
            {
                var result = new List<Laptop>();
                foreach(var laptop in laptops)
                {
                    if (laptop != null && (laptop.Brand == brand))
                    {                        
                        result.Add(laptop);
                    }
                }
                return result.ToArray();
            }
        }
    }
}
