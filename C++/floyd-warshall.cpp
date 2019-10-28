//floyd warshall algo 
//it uses dp
//all pair shortest path algo for directed weighted graph
//1st matrix as the adj matrix, the calc a1(i,j)=a0(i,1)+a0(1,j) and so on
//let's start...
#include<bits/stdc++.h>
using namespace std;

int adj[100][100];
set<int> nodes;
set<int> :: iterator itr,itr1,itr2;	
int n=0;

int addedge()
{
	int a=0,b=0,c=0,i=0,j=0,ch=0;
	cout<<"Enter directed(1)/undirected(2)";
	cin>>ch;
	cout<<"Enter number of edges";
	cin>>n;
	cout<<"Enter start node, end node and weight";
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		adj[a][b]=c;
		if(ch==2)
		adj[b][a]=c;
		nodes.insert(a);
		nodes.insert(b);
	}
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		if(adj[i][j]==0&&i!=j)
		adj[i][j]=1000;//don't use INT_MAX as it results in int overflow during checking
	}
}

int fw()
{
	int temp[100][100],i=0,j=0;
	copy(&adj[0][0],&adj[0][0]+10000,&temp[0][0]);
	for(itr2=nodes.begin();itr2!=nodes.end();itr2++)
	{
		int adjn[100][100];
		for(i=0;i<100;i++)
		{
			adjn[i][i]=0;
			adjn[i][*itr2]=temp[i][*itr2];
			adjn[*itr2][i]=temp[*itr2][i];	
		}
		for(i=0;i<100;i++)
		{
			for(j=0;j<100;j++)
			{
				if(temp[i][j]>abs(temp[i][*itr2]+temp[*itr2][j]))
				adjn[i][j]=temp[i][*itr2]+temp[*itr2][j];
				else
				adjn[i][j]=temp[i][j];
			}
		}
		copy(&adjn[0][0],&adjn[0][0]+10000,&temp[0][0]);
	}
	for(itr=nodes.begin();itr!=nodes.end();itr++)
	{
		for(itr1=nodes.begin();itr1!=nodes.end();itr1++)
		if(temp[*itr][*itr1]==1000)
		cout<<INT_MAX<<" ";
		else
		cout<<temp[*itr][*itr1]<<" ";
		cout<<endl;
	}
}

int main()
{
	addedge();
	fw();
	return 0;
}
