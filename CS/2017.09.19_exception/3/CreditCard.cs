using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19_3
{
    class CreditCard
    {
        private string pin;
        private const int MaxAttempts = 2;
        public string NumberCard { get; private set; }
        private int failedCount;

        public CreditCard(string number, string pin)
        {
            this.pin = pin;
            NumberCard = number;
            failedCount = 0;
        }

        public bool CheckPin(string pin)
        { 
           if (failedCount <= MaxAttempts)
           {
               throw new CreditCardLockedException();               
           }
           if (this.pin != pin)
           {
               failedCount++;

               throw new CreditCardException()
               {
                   RenaninigAteempts = MaxAttempts - failedCount
               };
           }
           return true;
        }

       
    }
}
