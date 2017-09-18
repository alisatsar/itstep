using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._18
{
    [Flags]
    public enum Permission
    {
        Read = 1,
        Write = 2,
        Execute = 4,
        Delete = 8,

        ReadWrite = Read | Write
    }
}
