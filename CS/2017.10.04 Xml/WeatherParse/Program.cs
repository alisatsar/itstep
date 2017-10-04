using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _2017._10._04_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("choose city");

            int index = 1;
            foreach(var city in Configuration.Instance.Cities)
            {
                Console.WriteLine($"{index++}.{city.Name}");
            }
            var input = Console.ReadLine();
            var selected = int.Parse(input);

            var selectedCity = Configuration.Instance.Cities[selected - 1];

            var url = $"http://informer.gismeteo.by/rss/{selectedCity.Code}.xml";

            using (var reader = new XmlTextReader(url))
            {
                var document = new XmlDocument();
                document.Load(reader);
                Console.WriteLine(document.OuterXml);
            }
        }
              
           
    }
}
