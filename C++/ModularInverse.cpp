#include <bits/stdc++.h>
using namespace std;

/* Fast exponentiation with mod */

int power(int base, int exp, int mod)
{
   if (exp == 0)
      return 1;
   if (exp == 1)
      return base;

   int x = power(base, exp / 2, mod);
   x *= x;
   if (exp % 2 == 1)
      x *= base;
   return x;
}

/* 
 * (If mod is prime) - Fermats's Litte Theorem:
 * 
 * a ^ (m - 1) === 1 (mod m)
 * Multiplying both sides by a ^ (-1)
 * a ^ (m - 2) === a ^ (-1) (mod m)
 * a ^ (-1) === a ^ (m - 2) (mod m)
 */

int modularInverse(int a, int m)
{
   a %= m;
   return power(a, m - 2, m);
}
