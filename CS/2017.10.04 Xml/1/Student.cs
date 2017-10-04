using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._10._04
{
    /// <summary>
    /// Represents IT academy student
    /// </summary>
    public class Student
    {
        /// <summary>
        /// Gets or sets the Name.
        /// </summary>
        public string Name { get; set; }
        /// <summary>
        /// Initialized a new instances of <see cref = 'Student1'/> class
        public Student()
        {

        }

        /// <summary>
        /// Provides an answer to the specified question<paramref name="question"/>
        /// </summary>
        /// <param name="question">Should end with question sign </param>
        /// <returns>Comma separated answers</returns>
        public string Answer(string question)
        {
            return "I don't know";
        }
    }
}
