using System;

namespace _2017._09._25_2
{
    public class MenuItem
    {
        public string Title { get; set; }

        public MenuItem(string title)
        {
            Title = title;
        }

        public virtual void SelectItem(MenuItem prev = null)
        {
            Console.Clear();
        }
    }
}
