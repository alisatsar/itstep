using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._10._07_exam
{
    public class Dispatcher
    {
        public string Name { get; private set; }
        public bool Active { get; set; }
        public string Id { get; private set; }
        public CityEnum city { get; set; }    
        public int AdjustmenWeatherConditions { get; set; }
        public bool StartControl { get; set; }
        public int RecommendedHeightFlight { get; set; }
        public int PenaltyPoints { get; set; }

        public Dispatcher(string name)
        {
            Random rand = new Random();
            Name = name;
            Id = GenerateID();
            Active = true;
            AdjustmenWeatherConditions = rand.Next(-200, 200);
            city = (CityEnum)rand.Next(1, 9);
            StartControl = false;
            PenaltyPoints = 0;
        }

        private string GenerateID()
        {
            DateTime date = DateTime.Now;            
            return date.Second.ToString() + Name;
        }  
        
        public void CheckAirplane(int speed, int height)
        {
            if (speed >= 50)
            {
                StartControl = true;
            }
            else if (speed < 50)
            {
                StartControl = false;
            }
            RecommendedHeightFlight = 7 * speed - AdjustmenWeatherConditions;
                        
        }
        
    }
}
