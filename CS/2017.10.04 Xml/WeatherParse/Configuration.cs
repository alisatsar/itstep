using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;

namespace _2017._10._04_2
{
    public sealed class Configuration
    {
        public static Configuration Instance { get; private set; } = new Configuration();

        static Configuration()
        {

        }

        private Configuration()
        {
            Load();
        }

        public List<City> Cities { get; private set; } = new List<City>();
        
        public void Load()
        {
            using (var file = File.OpenRead("Cities.config"))
            {
                var reader = new XmlTextReader(file);
                while(reader.Read())
                {
                    if (reader.Name == "city")
                    {
                        var cityName = reader.GetAttribute("Name");
                        var cityCode = reader.GetAttribute("Code");

                        var city = new City()
                        {
                            Name = cityName, 
                            Code = cityCode.Trim()
                        };
                        Cities.Add(city);
                    }
                }
            }
        }               
    }
}
