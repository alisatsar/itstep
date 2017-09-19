using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19_3
{
    class Program
    {
        static void Main(string[] args)
        {
            var autorized = false;
            CreditCard card = new CreditCard( "1270114445454", "0999" );            

            while(!autorized)
            {
                var pin = Console.ReadLine();

                try
                {
                    card.CheckPin(pin);
                    autorized = true;
                }
                catch (CreditCardException ex)
                {
                    Console.WriteLine("The wrong pin, you hane {0} tries", ex.RenaninigAteempts + 1);
                }
                catch (CreditCardLockedException ex)
                {
                    switch (ex.ErrorCode)
                    {

                    }
                    Console.WriteLine("Your card is locked");
                    break;
                }

            }
            
        }
    }
}
