#include<bits/stdc++.h>

using namespace std;
struct Points
{
	int x;
	int y;
};


int cross_product(Points a,Points b)
{
	return((a.x * b.y) - (a.y * b.x)); 
	
}
double solve(Points arr[],int n)
{
double sum=0;
int i;
for(i=0;i<n;i++)
{
	sum=sum+cross_product(arr[i],arr[(i+1)%n]);
	
}
return (abs(sum)/2);
}
int main()
{
	int i,n;
	cout<<"Enter the number of points\n";
	cin>>n;
	cout<<"Enter the coOrdinates\n";
	Points arr[n];
	for(i=0;i<n;i++)
	{
		Points t;
		cin>>t.x>>t.y;
		arr[i]=t;
		
	}
	double ans=solve(arr,n);
	cout<<"Area is= "<<ans<<endl;
}

	