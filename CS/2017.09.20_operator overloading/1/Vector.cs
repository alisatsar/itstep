using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._20
{
    public class Vector
    {
        public float DeltaX { get; set; }
        public float DeltaY { get; set; }

        public Vector()
        {

        }

        public Vector(Point begin, Point end)
        {
            DeltaX = end.xPos - begin.xPos;
            DeltaY = end.xPos - begin.xPos;
        }

        public static Vector operator+(Vector a, Vector b)
        {
           return new Vector()
           {
               DeltaX = a.DeltaX + b.DeltaX,
               DeltaY = b.DeltaY + b.DeltaY
           };
        }

        public static Vector operator*(Vector a, int i)
        {
            return new Vector()
            {
                DeltaX = a.DeltaX * i,
                DeltaY = a.DeltaY * i
            };
        }

        public static Vector operator*(int i, Vector a)
        {
            return a * i;            
        }

        public override string ToString()
        {
            return string.Format("DeltaX = {0}\nDeltaY = {1}", DeltaX, DeltaY);
        }

        public override bool Equals(object obj)
        {
            var a = (Vector)obj;
            return DeltaX == a.DeltaX && DeltaY == a.DeltaY;
        }

        public static bool operator==(Vector v1, Vector v2)
        {
            return v1.Equals(v2);
        }

        public static bool operator !=(Vector v1, Vector v2)
        {
            return !(v1 == v2);
        }

        public static bool operator> (Vector v1, Vector v2)
        {
            return Math.Sqrt(v1.DeltaX * v1.DeltaX + v1.DeltaY * v1.DeltaY) > Math.Sqrt(v2.DeltaX * v2.DeltaX + v2.DeltaY * v2.DeltaY);
        }

        public static bool operator<(Vector v1, Vector v2)
        {
            return Math.Sqrt(v1.DeltaX * v1.DeltaX + v1.DeltaY * v1.DeltaY) < Math.Sqrt(v2.DeltaX * v2.DeltaX + v2.DeltaY * v2.DeltaY);
        }
    }
}
