#include<bits/stdc++.h>
using namespace std;

int main ()
{
  int n,i;
  cout<<"enter no. of terms:";
  cin>>n;
  int f[n+2];
  f[0] = 0;
  f[1] = 1;
  cout<<f[0]<<" "<<f[1]<<" ";
  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];
      cout<<f[i]<<" ";
  }
  
  return 0;
}
