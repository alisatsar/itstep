using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._20
{
    public struct PointStruct
    {
        public float xPos { get; set; }
        public float yPos { get; set; }

        public PointStruct(float x, float y)
            :this()
        {
            xPos = x;
            yPos = y;
        }
    }
}
