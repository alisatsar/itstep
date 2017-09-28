using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._20
{
    public class Point
    {
        public float xPos { get; set; }
        public float yPos { get; set; }

        public Point(float x, float y)
        {
            xPos = x;
            yPos = y;
        }

        public static Point operator++(Point p)
        {
            p.xPos += 1.0f;
            p.yPos += 1.0f;

            return p;
        }

        public static Point operator--(Point p)
        {
            p.xPos -= 1.0f;
            p.yPos -= 1.0f;

            return p;
        }

        public static Point operator-(Point p)
        {
            return new Point(0, 0) { xPos = -p.xPos, yPos = -p.yPos };
        }

        public override string ToString()
        {
            return string.Format("x = {0}\ny = {1}", xPos, yPos);
        }
   
    }
}
