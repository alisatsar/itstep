using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._20_2
{
    public class Complex
    {
        public double A { get; set; }
        public double B { get; set; }

        public Complex(double a, double b)
        {
            A = a;
            B = b;
        }

        public override string ToString()
        {
            return string.Format("{0} {1: + 0;-#}i", A, B);
        }

        public static Complex operator-(Complex c1, Complex c2)
        {
            return new Complex(c1.A - c2.A, c1.B - c2.B);
        }

        public static Complex operator*(Complex c1, Complex c2)
        {
            return new Complex((c1.A * c2.A - c1.B * c2.B), (c1.B * c2.A + c1.A * c2.B));
        }

        public static Complex operator/(Complex c1, Complex c2)
        {
            double a = c1.A;
            double b = c1.B;
            double c = c2.A;
            double d = c2.B;

            return new Complex((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d));
        }

        public static Complex operator*(int i, Complex c)
        {
            return new Complex(i, 0) * c;
        }

        public static Complex operator-(Complex c, int i)
        {
            return c - new Complex(i, 0);
        }
    }
}
