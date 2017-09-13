using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._13
{
    class Program
    {
        static void Main(string[] args)
        {
            string SizeX = args[0];
            string SizeY = args[1];

            int SizeXInt;
            int SizeYInt;

            SizeXInt = int.Parse(SizeX);
            SizeYInt = int.Parse(SizeY);

            bool[,] matrix = new bool[SizeXInt, SizeYInt];

            string coordinateLife;
            int coordinateLifeX = 0;
            int coordianteLifeY = 0;


            string[] splitStr;

            for (int i = 2; i < args.Length; i++)
            {
                coordinateLife = args[i];
                splitStr = coordinateLife.Split(new[] { ',' });


                coordinateLifeX = int.Parse(splitStr[0]);
                coordianteLifeY = int.Parse(splitStr[1]);

                Console.SetCursorPosition(coordinateLifeX, coordianteLifeY);
                Console.WriteLine("@");

                
            }

            bool[,] nextGeneration = new bool[SizeXInt, SizeYInt];

            for(int i = 0; i < SizeXInt * SizeYInt; i++)
            {
                matrix[coordinateLifeX, coordianteLifeY] = true;
            }

            int count = 0;

            for (int i = 0; i < SizeXInt; i++)
            {
                for (int j = 0; j < SizeYInt; j++)
                {
                    if (matrix[i + 1, j] && (i < SizeXInt - 1))
                    {
                        ++count;
                    }
                    else if(matrix[i, j+1] && (j < SizeYInt - 1))
                    {
                        ++count;
                    }
                    else if(matrix[i - 1, j] && (i != 0))
                    {
                        ++count;
                    }
                    else if(matrix[i, j - 1] && (j != 0))
                    {
                        ++count;
                    }

                    if ((count == 4 || count == 0) && matrix[i, j] == true)
                    {
                        nextGeneration[i, j] = false;
                    }
                    else if(matrix[i, j] == false && count == 3)
                    {
                        nextGeneration[i, j] = true;
                    }
                    else
                    {
                        nextGeneration[i, j] = matrix[i, j];
                    }
                }
                    //nextGeneration[coordinateLifeX, coordianteLifeY] = true;
            }
       
        }
    }
}
