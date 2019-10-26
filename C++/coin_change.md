/*
PROBLEM STATEMENT:
You are given with m coins of different denominations S = {S1, S2, ..., Sm}. You have infinite supply of each type of coin.
Your task is to find the number of ways in which a total of N cents be generated.
*/

/*
APPROACH 1:
TIME COMPLEXITY: O(N*M)
SPACE COMPLEXITY: O(N*M)
*/

int coin_change_approach_1(vector<int> S, int N)
{
	int M=S.size();
	int dp[N][M+1];
	for(int i=0;i<=N;i++)
		for(int j=0;j<=M;j++)
			dp[i][j]=0;
	for(int i=0;i<=N;i++)
		dp[i][0]=1;
	for(int i=0;i<N;i++)
		for(int j=1;j<=M;j++)
			if(j<=S[i])
				dp[i][j]+=dp[i-1][j];
			else
				dp[i][j]+=dp[i][j-S[i]]+dp[i-1][j];
	return dp[N-1][M];
}

/*
APPROACH 2:
TIME COMPLEXITY: O(N*M)
SPACE COMPLEXITY: O(M)
*/

int coin_change_approach_2(vector<int> S, int N)
{
	int M=S.size();
	int dp[M+1];
	for(int i=0;i<=M;i++)
		dp[i]=0;
	dp[0]=1;
	for(int i=0;i<N;i++)
		for(int j=S[i];j<=M;j++)
				dp[j]+=dp[j-S[i]];
	return dp[M];
}
