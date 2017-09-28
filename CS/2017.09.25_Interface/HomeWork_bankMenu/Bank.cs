using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25_2
{
    public class Bank
    {
        public decimal Balance { get; private set; }

        internal void Deposit(decimal sum)
        {
            Balance += sum;
        }

        internal void Withdraw(decimal sum)
        {
            if (sum > Balance)
            {
                throw new ApplicationException("Not avalible sum");
            }

            Balance -= sum;
        }
    }
}
