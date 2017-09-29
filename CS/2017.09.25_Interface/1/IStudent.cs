using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._25
{
    public interface IStudent
    {
        string Name { get; set; }
        //int DoHomeWork { get; set; }
        string this[int i] { get; set; }

        
                
    }
}
