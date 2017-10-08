using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Weather;

namespace _2017._10._07_exam
{
    public class Dispatcher
    {
        public string Name { get; private set; }
        public bool Active { get; set; }
        public string Id { get; private set; }
        public City city { get; set; }    
        public int AdjustmenWeatherConditions { get; set; }

        public Dispatcher(string name)
        {
            Random rand = new Random();
            Name = name;
            Id = GenerateID();
            Active = true;
            AdjustmenWeatherConditions = rand.Next(-200, 200);
        }

        public void CheckWeater()
        {

        }

        private string GenerateID()
        {
            DateTime date = DateTime.Now;            
            return date.Second.ToString() + Name;
        }

       
    }
}
