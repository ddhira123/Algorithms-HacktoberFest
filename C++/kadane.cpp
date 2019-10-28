//kadane algo for max sum subarray			gfg
#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n)
{
	int max_now=0,sum_now=0,i=0;
	for(i=0;i<n;i++)
	{
		sum_now+=arr[i];
		if(sum_now<0)
		sum_now=0;
		if(sum_now>max_now)
		max_now=sum_now;
	}
	return max_now;
}
int main()
{
	int arr[]={4, 1, -2, -2, -3, 1, 5, 3},n=sizeof(arr)/sizeof(int);
	cout<<kadane(arr,n);
	return 0;
}
