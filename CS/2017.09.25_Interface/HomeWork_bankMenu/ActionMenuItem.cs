using _2017._09._25_2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25_2
{
    public class ActionMenuItem : MenuItem
    {
        private IHandle handler;
        public ActionMenuItem(string title, IHandle handler) 
            : base(title)
        {
            this.handler = handler;
        }
        public override void SelectItem(MenuItem prev = null)
        {

            base.SelectItem(prev);
            try
            {
                this.handler.Handle();

            }
            catch (ApplicationException ex)
            {
                Console.WriteLine("Wrong: {0}", ex.Message);
            }
            
            Console.WriteLine("Press any key to continue");
            Console.ReadLine();
            prev.SelectItem(null);
        }
    }
}
