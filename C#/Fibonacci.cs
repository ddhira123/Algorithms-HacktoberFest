using System;
using System.Text;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("Insert the term: ");
            var term = int.Parse(Console.ReadLine());

            System.Console.WriteLine(FibRecursive(term));
        }
        static int FibRecursive(int term)
        {
            if(term ==  1 || term == 2)
            {
                return 1;
            }

            return FibRecursive(term-1) + FibRecursive(term -2 );
        }
    }
}
