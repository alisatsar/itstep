using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary1
{
    public class Car
    {
        private readonly string model;
        private int speed;

        private Driver driver;
        private Tank tank;

        public Car(string model, int speed, Driver driver, Tank tank)
        {
            this.model = model;
            this.speed = speed;
            this.tank = tank;
            this.driver = driver;
        }
        public void Accolerate()
        {
            speed += 10;
        }
    }
}
