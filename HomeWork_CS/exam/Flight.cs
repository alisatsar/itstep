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
        public Dispatcher Dispatcher1 { get; private set; }
        public Dispatcher Dispatcher2 { get; private set; }
        public Pilot Pilot { get; set; }
        public List<Dispatcher> allDispatcher = new List<Dispatcher>();

        public Flight(string pilotName)
        {
            Pilot = new Pilot(pilotName);                   
        }

        public void AddDispatcher()
        {
            string name = Pilot.AddDispetcher();
            Dispatcher1 = new Dispatcher(name);
            allDispatcher.Add(Dispatcher1);
            name = Pilot.AddDispetcher();
            Dispatcher2 = new Dispatcher(name);
            allDispatcher.Add(Dispatcher2);
        }

        public void ChangeDispatcher()
        {
            int answerInt;
            do
            {
                Console.WriteLine("Enter a number of dispatcher, which you want to change: ");
                Console.WriteLine("1 - {0}\n2 - {1}\n3 - exit", Dispatcher1.Name, Dispatcher2.Name);
                string answerStr = Console.ReadLine();
                answerInt = int.Parse(answerStr);

                if (answerInt == 3) { return; }

            } while (answerInt != 1 && answerInt != 2);

            if (answerInt == 1)
            {
                Dispatcher1.Active = false;
                Dispatcher1 = new Dispatcher(Pilot.AddDispetcher());
                allDispatcher.Add(Dispatcher1);
            }
            else
            {
                Dispatcher2.Active = false;
                Dispatcher2 = new Dispatcher(Pilot.AddDispetcher());
                allDispatcher.Add(Dispatcher2);
            }
        }

        public void StartFlight()
        {
            if(Dispatcher1.Active && Dispatcher2.Active)
            {
                StartFlight fly = new StartFlight();

                while(true)
                {
                    fly.Flight += (o, e) => Console.WriteLine(e.Speed);
                    fly.Start();
                }
                

            }
        }
    }
}
