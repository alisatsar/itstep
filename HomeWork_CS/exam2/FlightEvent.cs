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
        public bool IsFinished { get; set; }

        public FlightEvent(int speed, int height, bool isFinished)
        {            
            Speed = speed;
            Height = height;
            IsFinished = isFinished;
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

            FlightEvent events;
            do
            {
                var key = Console.ReadKey();
                Func<int, int> changeSpeed = null;
                Func<int, int> changeHeignt = null;
                Func<bool, bool> changeFinished = null;

                if(key.Key == ConsoleKey.LeftArrow)
                {
                    if(key.Modifiers == ConsoleModifiers.Control)
                    {
                        changeSpeed = (x) => x - 150;
                        changeHeignt = (y) => y;
                        changeFinished = (z) => z;
                    }
                    changeSpeed = (x) => x - 50;
                    changeHeignt = (y) => y;
                    changeFinished = (z) => z;
                }
                else if(key.Key == ConsoleKey.RightArrow)
                {
                    changeSpeed = (x) => x + 50;
                    changeHeignt = (y) => y;
                    changeFinished = (z) => z;
                }
                else if(key.Key == ConsoleKey.LeftArrow && key.Modifiers == ConsoleModifiers.Shift)
                {
                    changeSpeed = (x) => x - 150;
                    changeHeignt = (y) => y;
                    changeFinished = (z) => z;
                }
                else if(key.Key == ConsoleKey.RightArrow && key.Modifiers == ConsoleModifiers.Shift)
                {
                    changeSpeed = (x) => x + 150;
                    changeHeignt = (y) => y;
                    changeFinished = (z) => z;
                }
                
                var resultSpeed = changeSpeed(0);
                var resultHeight = changeHeignt(0);
                var reusulFinished = changeFinished(false);

                events = new FlightEvent(resultSpeed, resultHeight, reusulFinished);
                OnStartFly(events);
            } while (!events.IsFinished);           
        }

        private void OnStartFly(FlightEvent events)
        {
            var handler = Flight;//handler указатель на функцию

            if (handler != null)
            {
                handler(this, events);
            }
        }
    }   
}
