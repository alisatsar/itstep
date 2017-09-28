using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25_2
{
    public  class ShowBalanceHandler : BankHandler 
    {
        public ShowBalanceHandler(Bank bank)
            :base(bank)
        {            
        }
        public override void Handle()
        {
            Console.WriteLine("Your Balance: {0}", Bank.Balance);
        }
    }
}
