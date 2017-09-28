using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25_2
{
    public abstract class BankHandler : IHandle
    {
        protected Bank Bank { get; private set; }

        public BankHandler(Bank bank)
        {
            Bank = bank;
        }

        public abstract void Handle();
        protected decimal AskAmount()
        {
            Console.WriteLine("Enter sum");
            var sumDeposit = Console.ReadLine();

            var sum = decimal.Parse(sumDeposit);
            return sum;
        }
    }
}
