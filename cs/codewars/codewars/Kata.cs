using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading.Tasks;

namespace codewars
{
    internal class Kata
    {
        public static int[] Divisors(int n)
        {
            List<int> result = new List<int>();

            int square = (int)Math.Sqrt(n);

            for (int i = 2; i <= square; i++)
            {
                if (n % i == 0)
                {
                    result.Add(i);
                    if (i != n / i)
                    {
                        result.Add(n / i);
                    }
                }
            }
            if (result.Count == 0)
                return null;

            result.Sort();
            return result.ToArray();
        }
    }
}