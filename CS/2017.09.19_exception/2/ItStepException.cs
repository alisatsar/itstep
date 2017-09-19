using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19_2
{
    [Serializable]
    public class ItStepException : Exception
    {
        public ItStepException() { }
        public ItStepException(string message) : base(message) { }
        public ItStepException(string message, Exception inner) : base(message, inner) { }
        protected ItStepException(
              System.Runtime.Serialization.SerializationInfo info,
              System.Runtime.Serialization.StreamingContext context)
                : base(info, context) { }
        
    }
}
