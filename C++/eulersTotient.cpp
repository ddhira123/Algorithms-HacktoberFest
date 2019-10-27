#include <bits/stdc++.h>
using namespace std;

/*
 * Euler's Totient Function:
 * 
 * Calculates the amount of x, where 1 <= x <= n that
 * are coprime with n (gcd(x, n) == 1)
 */

int phi(int n)
{
   int ans = n;

   for (int p = 2; p * p <= n; p++)
      if (n % p == 0)
      { // All primes factors
         while (n % p == 0)
            n /= p;
         ans -= ans / p; // Subtract all x that are divisible by p
      }

   if (n > 1)
      ans -= ans / n; // There can't be more than one prime
                      // factor that is bigger than sqrt(n)
   return ans;
}
