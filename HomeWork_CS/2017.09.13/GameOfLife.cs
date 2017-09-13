/*Распределение живых клеток в начале игры называется первым поколением. 
 * Каждое следующее поколение рассчитывается на основе предыдущего по таким правилам:
1. в пустой (мёртвой) клетке, рядом с которой ровно три живые клетки, зарождается жизнь;
2. если у живой клетки есть две или три живые соседки, то эта клетка продолжает жить;
3. в противном случае, если соседей меньше двух или больше трёх, клетка умирает («от одиночества» или «от перенаселённости»)

Игра прекращается, если
на поле не останется ни одной «живой» клетки
конфигурация на очередном шаге в точности (без сдвигов и поворотов) 
повторит себя же на одном из более ранних шагов (складывается периодическая конфигурация)
при очередном шаге ни одна из клеток не меняет своего состояния (складывается стабильная конфигурация;
предыдущее правило, вырожденное до одного шага назад)*/

using System;
using System.Text;

namespace _2017._09._13_HomeWork
{
    class Program
    {
        static void Main(string[] args)
        {
            string SizeX = args[0];
            string SizeY = args[1];

            int SizeXInt;
            int SizeYInt;

            SizeXInt = int.Parse(SizeX);//размерность массива
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
                Console.WriteLine("x");

                matrix[coordinateLifeX, coordianteLifeY] = true;
            }

            bool[,] nextGeneration = new bool[SizeXInt, SizeYInt];

            int count = 0;

            StringBuilder str = new StringBuilder();

            var key = Console.ReadKey();

            while(key.Key == ConsoleKey.Enter)
            { 
                for (int x = 0; x < SizeXInt; x++)
                {
                    for (int y = 0; y < SizeYInt;  y++)
                    {
                        if ((x < SizeXInt - 1) && matrix[x + 1, y])
                        {
                            ++count;
                        }
                        if ((y < SizeYInt - 1) && matrix[x, y + 1])
                        {
                            ++count;
                        }
                        if ((x != 0) && matrix[x - 1, y])
                        {
                            ++count;
                        }
                        if ((y != 0) && matrix[x, y - 1])
                        {
                            ++count;
                        }
                        if ((x != SizeXInt - 1) && (y != SizeYInt - 1) && matrix[x + 1, y + 1])
                        {
                            ++count;
                        }
                        if ((x != 0) && (y != SizeYInt - 1) && matrix[x - 1, y + 1])
                        {
                            ++count;
                        }
                        if ((x != 0) && (y != 0) && matrix[x - 1, y - 1])
                        {
                            ++count;
                        }
                        if ((x != SizeXInt - 1) && (y != 0) && matrix[x + 1, y - 1])
                        {
                            ++count;
                        }

                        if ((count == 2 || count == 3) && matrix[x, y] == true)
                        {
                            nextGeneration[x, y] = true;
                        }
                        else if (matrix[x, y] == false && count == 3)
                        {
                            nextGeneration[x, y] = true;
                        }
                        else if (matrix[x, y] == true && (count < 2 || count > 3))
                        {
                            nextGeneration[x, y] = false;
                        }
                        else
                        {
                            nextGeneration[x, y] = matrix[x, y];
                        }

                        count = 0;

                        if (nextGeneration[x, y] == true)
                        {
                            str.Append("x");
                        }
                        else if ((y == SizeYInt - 1) && (nextGeneration[x, y] == true))
                        {
                            str.Append("x").Append("\n");
                        }
                        else if ((y == SizeYInt - 1) && (nextGeneration[x, y] == false))
                        {
                            str.Append(" ").Append("\n");
                        }
                        else
                        {
                            str.Append(" ");
                        }
                    }                
                }
                Console.Clear();         
                Console.WriteLine(str);
                key = Console.ReadKey();
                str.Clear();
            }
        }
    }
}
