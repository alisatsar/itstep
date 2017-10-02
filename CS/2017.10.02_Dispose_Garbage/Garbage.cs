using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace _2017._10._02
{
    public class Garbage : IDisposable
    {
        private int[] array = new int[100000];
        IntPtr pointer = Marshal.AllocHGlobal(10000);
        public void Dispose()
        {
            Console.WriteLine("Disposed!");
            Marshal.FreeHGlobal(pointer);
        }

        /*~Garbage()
        {
            Console.WriteLine("Finalized!");
        }*/
    }
}
