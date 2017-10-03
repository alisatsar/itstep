using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace _2017._10._03
{
    class Program
    {
        static void Main(string[] args)
        {
            SelectDirectory(".");

            using (var stream = File.Create("test.txt", 10000))
            {
                Console.WriteLine(stream.Name);
                stream.WriteByte(123);

                using(var writer = new StreamWriter(stream))
                {
                    writer.WriteLine("Hello");
                    writer.WriteLine(10);
                    writer.WriteLine(true);
                    writer.Flush();//если не использовать using
                }                        
            }


            using (var stream = File.OpenRead("test.txt"))
            {
                Console.WriteLine(stream.ReadByte());

                using (var reader = new StreamReader(stream))
                {
                    Console.WriteLine(reader.ReadLine());
                }
            }
         
            using (var stream = new FileStream("test.bin", FileMode.Create, FileAccess.ReadWrite))
            {
                var writer = new BinaryWriter(stream);
                writer.Write("Hello");
                writer.Write(10);
                writer.Write(true);
                writer.Flush();
                writer.Seek(0, SeekOrigin.Begin);

                using(var reader = new BinaryReader(stream))
                {
                    Console.WriteLine(reader.ReadString());
                    Console.WriteLine(reader.ReadInt32());
                    Console.WriteLine(reader.ReadBoolean());
                }
            }
            Console.ReadLine();
        }

        public static void SelectDirectory(string current)
        {
            if (!Directory.Exists(current))
            {
                Console.WriteLine("Directory is not found.");
                return;
            }

            var info = new DirectoryInfo(current);
            Console.WriteLine(info.FullName);

            foreach(var subDir in info.GetDirectories())
            {
                Console.WriteLine(subDir.Name);
            }

            foreach (var file in info.GetFiles())
            {
                Console.WriteLine(file.Name);
            }
        }
    }
}
