using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19_3
{
    [Serializable]
    public class CreditCardLockedException : Exception
    {
        enum rrorcode
        {
            Locked, 
            NotE
        }

        public rrorcode ErrorCode { get; set; }

        public CreditCardLockedException() { }
        public CreditCardLockedException(string message) : base(message) { }
        public CreditCardLockedException(string message, Exception inner) : base(message, inner) { }
        protected CreditCardLockedException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }
    }
}
