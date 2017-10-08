using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._10._07_exam
{
    
    public class FlightEvent : EventArgs
    {
        public int Speed { get; set; }
        public int Height { get; set; }

        public FlightEvent(int speed, int height)
        {            
            Speed = speed;
            Height = height;
        }        
    }

    public class StartFlight
    {
        public event EventHandler<FlightEvent> Flight;

        public void Start()
        {           
            Console.WriteLine("Speed — modified arrow keys Left and Right\n" +
                "(Right: +50 км/ч, Left: –50 км/ч, Shift-Right: +150 км/ч, Shift - Left: –150км / ч)");
            Console.WriteLine("Height — changes the arrow keys Up and Down:\n" +
                "(Up: +250 м, Down: –250 м, Shift-Up: +500 м, Shift-Down: –500м)");
            var key = Console.ReadKey();

            int speed = airplane.speed;
            int height = 0;

            Func<int, int> changeSpeed = null;
            Func<int, int> changeHeignt = null;

            
            switch (key.Key)
            {
                case ConsoleKey.LeftArrow:
                    changeSpeed = (x) => x + 50;
                    
                    break;
                case ConsoleKey.RightArrow:
                    changeSpeed = (x) => x - 50;                    
                    break;
            }
            var resultSpeed = changeSpeed(speed);
            var resultHeight = changeSpeed(height);

            OnStartFly(resultSpeed, resultHeight);
        }

        private void OnStartFly(int resultSpeed, int resultHeignt)
        {
            var handler = Flight;//handler указатель на функцию

            if (handler != null)
            {
                handler(this, new FlightEvent(resultSpeed, resultHeignt));
            }
        }
    }
}
