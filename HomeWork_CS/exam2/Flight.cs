using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._10._07_exam
{ 
    public class Flight
    {
        public Airplane airplane = new Airplane();        
        public Pilot Pilot { get; set; }
        public List<Dispatcher> allDispatcher = new List<Dispatcher>();
        public int CountActiveDispatchers { get; set; }

        public Flight(string pilotName)
        {
            Pilot = new Pilot(pilotName);
            CountActiveDispatchers = 0;
        }

        public void AddDispatcher()
        {
            string name = Pilot.AddDispetcher();
            Dispatcher dispatcher = new Dispatcher(name);
            allDispatcher.Add(dispatcher);
            CountActiveDispatchers++;
        }

        public void DeleteDispatcher()
        {
            Console.WriteLine("Enter a number of dispatcher, which you want to change: ");
            int index = 0;
            Dispatcher disp;
            foreach (var dispet in allDispatcher)
            {
                if (dispet.Active)
                {
                    Console.WriteLine($"{index} - {dispet.Name}");
                }
                index++;
            }
            int answerInt;
            do
            {                
                string answerStr = Console.ReadLine();
                answerInt = int.Parse(answerStr);

                if (answerInt == 3) { return; }

            } while (answerInt < 0 && answerInt >= allDispatcher.Count);

            disp = allDispatcher[answerInt];

            allDispatcher.Remove(disp);
            CountActiveDispatchers--;

            if (CountActiveDispatchers < 2)
            {
                AddDispatcher();
            }            
        }        

        public void StartFlight()
        {
            if(CountActiveDispatchers >= 2)
            {
                StartFlight fly = new StartFlight();

                fly.Flight += (o, e) => { airplane.Speed += e.Speed;                    
                    Console.WriteLine(airplane.Speed);                    
                };

                fly.Flight += (o, e) => {
                    airplane.Height += e.Height;                    
                    Console.WriteLine(airplane.Height);
                };

                fly.Flight += (o, e) =>
                {               
                    if (airplane.Speed < 0)
                    {
                        e.IsFinished = true;
                    }                    
                };

                foreach (var d in allDispatcher)
                {
                    if (d.Active)
                    {
                        d.CheckAirplane(airplane.Speed, airplane.Height);
                    }
                }               

                fly.Start();
            }
        }
    }
}
