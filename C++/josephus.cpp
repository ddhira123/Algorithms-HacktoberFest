#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int josephus(int n, int k)
{
       int a[n],i;
       for(i=1;i<=n;i++)
       a[i]=0;
       int count=n;
       for(i=k;count!=1;)
       {
			      
           if(i>n)
           i=i%n;
           if(a[i]==0)
           {
               a[i]=1;
               count--;
               
           }
		   else
		   {
			   while(a[i]==0)
				   i++;
			   continue;
		   }			   
		   
		   i=i+k-1;
	   }
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k);
		
	}
}



