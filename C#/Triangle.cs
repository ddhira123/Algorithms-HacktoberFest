using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            int a, b, c = 0;
            Console.WriteLine("Type a valor: ");
            a = int.Parse(Console.ReadLine());
            Console.WriteLine("Type a valor: ");
            c = int.Parse(Console.ReadLine());
            Console.WriteLine("Type a valor: ");
            b = int.Parse(Console.ReadLine());
            Triangle(a, b, c);
        }
        static void Triangle(int a, int b, int c)
        {
            if (a <= 0 || b <= 0 || c <= 0)
            {
                Console.WriteLine("This values doesn't make a triangle");
            }
            else if (a == b && b == c)
            {
                Console.WriteLine("This triangle is equilateral");
            }
            else if (a == b || b == c || c == a)
            {
                Console.WriteLine("This triangle is isosceles");
            }
            else if (a != b && b != c && a != c)
            {
                Console.WriteLine("This triangle is scaleno");
            }
        }
    }
}
