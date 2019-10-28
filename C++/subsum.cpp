//subset sum = a given sum			tushar roy
#include<bits/stdc++.h>
using namespace std;

int subsum(int arr[],int sum,int l)
{
	int i=0,j=0;
	int dp[l][sum+1];
	for(i=0;i<=sum;i++)
	if(arr[0]>i)dp[0][i]=0;
	else
	dp[0][i]=arr[0]; 
	for(i=0;i<l;i++)dp[i][0]=0;
	for(i=1;i<l;i++)
	for(j=1;j<=sum;j++)
	{
		if(j<arr[i])
		dp[i][j]=dp[i-1][j];
		else
		dp[i][j]=arr[i]+dp[i-1][j-arr[i]];
	}
		for(i=0;i<l;i++)
	{
	for(j=0;j<=sum;j++)
	cout<<dp[i][j]<<" ";
	cout<<endl;}
	for(i=0;i<l;i++)
	if(dp[i][sum]==sum)
	return 1;
	return 0;
}

int main()
{
	int arr[]={7,2,8,3,10},sum=11;
	int l=sizeof(arr)/sizeof(int);
	if(subsum(arr,sum,l))cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
