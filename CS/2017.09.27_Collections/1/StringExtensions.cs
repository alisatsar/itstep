using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._27
{
    public static class StringExtensions
    {
        public static string RemoveSpaces(this string str)
        {
            if (str == null)
            {
                return null;
            }            
            return str.Replace(" ", string.Empty);
        }
    }
}
