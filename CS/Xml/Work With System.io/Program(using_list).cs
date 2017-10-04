using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            List<User> users = new List<User>();

            XmlDocument xDoc = new XmlDocument();
            xDoc.Load("XMLFile1.xml");
            XmlElement xRoot = xDoc.DocumentElement;

            foreach(XmlElement xNode in xRoot)
            {
                User us = new User();

                XmlNode attr = xNode.Attributes.GetNamedItem("name");
                if (attr != null)
                {
                    us.Name = attr.Value;
                }

                foreach(XmlNode childNode in xNode.ChildNodes)
                {
                    if (childNode.Name == "company")
                    {
                        us.Company = childNode.InnerText;
                    }
                    if (childNode.Name == "age")
                    {
                        us.Age = int.Parse(childNode.InnerText);
                    }
                }
                users.Add(us);
            }
        }
    }
}
