//0/1 knap, video by tushar roy, eg from gfg				
#include<bits/stdc++.h>
using namespace std;

int wt[]={10,20,30},val[]={60,100,120},n=3,weight=50;
//int wt[]={1,3,4,5},val[]={1,4,5,7},n=4,weight=7;

int knap(int w,int i)
{
	if(i==n||w<=0)
	return 0;
	//if current weight has a weight greater than the remaining knap value
	if(wt[i]>w)
	return knap(w,i+1);
	//choose max between the two branches if the current value is chosen or not
	return max(val[i]+knap(w-wt[i],i+1),knap(w,i+1));
}

int knaptab()
{
	int dp[n][weight+1],i=0,j=0;
	for(i=0;i<n;i++)dp[i][0]=0;
	for(i=1;i<weight+1;i++)
	if(wt[0]>i)dp[0][i]=0;
	else
	dp[0][i]=val[0];
	for(i=1;i<n;i++)
	{
		for(j=1;j<weight+1;j++)
		{
			if(wt[i]>j)dp[i][j]=dp[i-1][j];
			else
			dp[i][j]=max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
		}
	}
	return dp[n-1][weight];
}
int main()
{
	cout<<knap(weight,0);//memoize
	cout<<knaptab();//tabulation
	return 0;
}
