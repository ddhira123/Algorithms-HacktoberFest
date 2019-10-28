//longest common subsequence			tushar roy
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2)
{
	int dp[s1.length()][s2.length()],i=0,j=0;
	for(i=0;i<s1.length();i++)dp[0][i]=1;
	for(i=0;i<s2.length();i++)dp[i][0]=1;
	for(i=1;i<s1.length();i++)
	for(j=1;j<s2.length();j++)
	if(s1[i]==s2[j])
	dp[i][j]=dp[i-1][j-1]+1;
	else
	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	return dp[s1.length()-1][s2.length()-1];
	
}

int main()
{
	string s1="acbcf",s2="abcdaf";
	cout<<lcs(s1,s2);
	return 0;
}
