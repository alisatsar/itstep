using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._27_2
{
    class WorkCounter
    {
        public void Work()
        {
            var input = Console.ReadLine();

            var separators = new[] { ' ', '.', ',', '-', ':' };
            var words = input.Split(separators).Where(x => !string.IsNullOrEmpty(x)).ToArray(); //(x => ;x.Length > 0

            var dictionary = new Dictionary<string, int>(StringComparer.InvariantCultureIgnoreCase);

            foreach(var word in words)
            {
                if(dictionary.ContainsKey(word))
                {
                    dictionary[word]++;
                }
                else
                {
                    dictionary[word] = 1;
                }
            }

            foreach(var key in dictionary.Keys)
            {
                Console.WriteLine("{0} {1}",key, dictionary[key]);
            }

            var lookup = words.ToLookup(x => x, StringComparer.InvariantCultureIgnoreCase);

            foreach (var l in lookup)
            {
                Console.WriteLine("{0} {1}", l.Key, l.Count());
            }
        }
    }
}
