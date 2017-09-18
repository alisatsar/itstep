using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibrary1;

namespace _2017._09._14_car
{
   class Program
    {
       static void Main(string[] args)
       {
          Tank tank = new Tank(3);
          Driver driver = new Driver("Volodya", 5);
          Car car = new Car("VW Polo", 100, driver, tank);
       }
    }
}
