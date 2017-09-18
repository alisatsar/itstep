using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._18
{
    public struct Point
    {
        private int x;
        private int y;
        private int[] array;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;

            array = new []{ 1, 3 };
        }

        public int GetX()
        {
            return x;
        }

        public int GetY()
        {
            return y;
        }

        public override string ToString()
        {
            return string.Format(" Struct x = {0}, y = {1}", x, y);
        }
        public void SetX(int x)
        {
            this.x = x;
        }
        public void SetY(int y)
        {
            this.y = y;
        }

    }
}
