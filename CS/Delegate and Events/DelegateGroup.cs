using System;

namespace Deleg
{
    public delegate void ProgresReporter(int percentComplete);

    public class Util
    {
        public static void HardWord(ProgresReporter p)
        {
            for (int i = 0; i < 10; i++)
            {
                p(i * 10); //Вызвать делегат
                System.Threading.Thread.Sleep(100);//эмулировать длительную работу
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            ProgresReporter p = WriteProgressToConsole;
            p += WriteProgressToFile;
            Util.HardWord(p);
        }
        static void WriteProgressToConsole(int percentComplete) => Console.WriteLine(percentComplete);
        static void WriteProgressToFile(int percentComplete) => System.IO.File.WriteAllText("progress.txt", percentComplete.ToString());        
    }    
}
