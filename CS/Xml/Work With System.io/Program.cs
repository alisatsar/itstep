/*Для работы с XML в C# можно использовать несколько подходов. В первых версиях фреймворка основной функционал работы с XML предоставляло пространство имен System.Xml. В нем определен ряд классов, которые позволяют манипулировать xml-документом:
XmlNode: представляет узел xml. В качестве узла может использоваться весь документ, так и отдельный элемент
XmlDocument: представляет весь xml-документ
XmlElement: представляет отдельный элемент. Наследуется от класса XmlNode
XmlAttribute: представляет атрибут элемента
XmlText: представляет значение элемента в виде текста, то есть тот текст, который находится в элементе между его открывающим и закрывающим тегами
XmlComment: представляет комментарий в xml
XmlNodeList: используется для работы со списком узлов

Ключевым классом, который позволяет манипулировать содержимым xml, является XmlNode, поэтому рассмотрим некоторые его основные методы и свойства:
Свойство Attributes возвращает объект XmlAttributeCollection, который представляет коллекцию атрибутов
Свойство ChildNodes возвращает коллекцию дочерних узлов для данного узла
Свойство HasChildNodes возвращает true, если текущий узел имеет дочерние узлы
Свойство FirstChild возвращает первый дочерний узел
Свойство LastChild возвращает последний дочерний узел
Свойство InnerText возвращает текстовое значение узла
Свойство InnerXml возвращает всю внутреннюю разметку xml узла
Свойство Name возвращает название узла. Например, <user> - значение свойства Name равно "user"
Свойство ParentNode возвращает родительский узел у текущего узла*/

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
            XmlDocument xDoc = new XmlDocument();
            xDoc.Load("XMLFile1.xml");
            //Получить корневой элемент
            XmlElement xRoot = xDoc.DocumentElement;
            //обход всех узлов в корневом элементе
            foreach(XmlNode xnode in xRoot)
            {
                //получаем атрибут name
                if (xnode.Attributes.Count > 0)
                {
                    XmlNode attr = xnode.Attributes.GetNamedItem("name");
                    if (attr != null)
                    {
                        Console.WriteLine(attr.Value);
                    }
                }
                //Обходим все дочерние узлы элемента user
                foreach(XmlNode childNode in xnode.ChildNodes)
                {
                    //если узел - company
                    if(childNode.Name=="company")
                    {
                        Console.WriteLine("Company: {0}", childNode.InnerText);
                    }
                    if(childNode.Name == "age")
                    {
                        Console.WriteLine("Age: {0}", childNode.InnerText);
                    }
                }
            }
        }
    }
}
