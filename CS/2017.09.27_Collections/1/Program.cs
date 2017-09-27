using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace _2017._09._27
{
    class Program
    {
        static void Main(string[] args)
        {
            /*var input = Console.ReadLine();

            StringExtensions.RemoveSpaces(input);

            Console.WriteLine(input.RemoveSpaces());

            var arr = new int[10];

            //arr.Where(x => x > 0).Select(x => x* x).FirstOrDefault(x => x == 9);

            int page = 0;

            int perPage = 5;

            arr = arr.Skip(page * perPage).Take(perPage).ToArray();//skip пропускает элементы take. берет  элементы в массив*/

            var list = new List<Student>()
            {
                new Student() {Name = "Sergey", Surname = "s", BirthDate = new DateTime(1988, 5, 24)},
                new Student() {Name = "Alisa", Surname = "sfd", BirthDate = new DateTime(1987, 6, 11)},
                new Student() {Name = "Maxim", Surname = "dhgh", BirthDate = new DateTime(1988, 3, 3)},
                new Student() {Name = "Lenya", Surname = "sfdg", BirthDate = new DateTime(1988, 12, 19)},
                new Student() {Name = "Lev", Surname = "qer", BirthDate = new DateTime(1988, 11, 1)},
            };

            //list.Print();

            //list.OrderBy(x => x.Name).Print();

            //list.OrderBy(x => x.BirthDate.GetAge()).Print();


            var enumerator = list.GetEnumerator();
            while(enumerator.MoveNext())
            {
                var student = enumerator.Current;
                student.Print();
            }

            var arrayList = new ArrayList();
            arrayList.Add(1);

            arrayList.Add("string");
            arrayList.Add(new Student());

            Stack<string> stack = new Stack<string>();
            stack.Push("One");
            stack.Push("Two");
            stack.Push("Three");
            Console.WriteLine(stack.Pop());
            Console.WriteLine(stack.Count());
            Console.WriteLine(stack.Peek());


            var q1 = new Student() {Name = "Sergey", Surname = "s", BirthDate = new DateTime(1988, 5, 24)};
            var q2 = new Student() {Name = "Alisa", Surname = "sfd", BirthDate = new DateTime(1987, 6, 11)};
            var q3 = new Student() {Name = "Maxim", Surname = "dhgh", BirthDate = new DateTime(1988, 3, 3)};

            Queue<Student> queue = new Queue<Student>();
            queue.Enqueue(q1);
            queue.Enqueue(q2);
            queue.Enqueue(q3);
            queue.Dequeue().Print();

            var sList = new SortedList<string,Student>();
            sList.Add(q1.Name, q1);
            sList.Add(q2.Name, q2);
            sList.Add(q3.Name, q3);
            sList.Values.Print();

            var dictionary = new Dictionary<string, int>();

            dictionary.Add("one", 5);
            dictionary["two"] = 3;

            if (dictionary.ContainsKey("three"))
            {
                dictionary["two"]++;
            }
            else
            {
                dictionary["two"] = 2;
            }

            int result;

            if (dictionary.TryGetValue("two", out result))
            {
                result++;
            }

            Console.WriteLine(dictionary["two"]);


            var mapInMap = new Dictionary<string, Dictionary<string, string>>()
            {
                {"two",  new Dictionary<string, string>()
                    {
                        {"three", "dslfs"},
                        {"four", "sljflsf"}
                    }
                }
            };

            Console.WriteLine(mapInMap["two"]["three"]);

            foreach(var pair in dictionary)
            {
                Console.WriteLine(pair.Key + pair.Value);
            }

            var lookup = list.ToLookup(x => x.Name);

            lookup["Sergey"].Print();


            var lookup2 = list.GroupBy(x => x.Name);

            lookup.Contains("Serger");
        }
    }
}
