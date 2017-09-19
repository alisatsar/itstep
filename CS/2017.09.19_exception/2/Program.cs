using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2017._09._19_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var exception = new ItStepException();
            
            /*try
            {
                throw new ItStepException("Hello");
                throw exception;
            }
            catch(ItStepException ex)
            {
                Console.WriteLine(ex.Message, ex.StackTrace, ex.InnerException);
                Console.WriteLine(ex.StackTrace);
            }*/


            try
            {
                checked//генерирует исключения в случае переполнения 
                {
                    byte b = 100;
                    b += 200;
                    Console.WriteLine(b);
                }                
                
            }
            catch (Exception ex)//после версии 6.0 catch(Exception ex whtn(ex.Message.Contains("содержит какое-то слово"))
            {
                Console.WriteLine(ex.Message);
            }
            
        }
    }
}
