using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19_3
{
    [Serializable]
    public class CreditCardException : Exception
    {
        public int RenaninigAteempts{get; set;}

        public CreditCardException() { }
        public CreditCardException(string message) : base(message) { }
        public CreditCardException(string message, Exception inner) : base(message, inner) { }
        protected CreditCardException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }
    }
}
