using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25
{
    public interface IGotStudent : IStudent
    {
        decimal Salary { get; set; }
    }
}
