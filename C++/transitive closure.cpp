//transitive closure means a matrix which stores the pathways from all vertices to another.
//solved by warshall algo
//what it does is puts weight of 1 in all paths and solve by floyd-warshall
//we can also solve by running dfs in wach row, which is solved here
#include<bits/stdc++.h>
using namespace std;

map<int,vector<int> > adj;
vector<int>  :: iterator itr;
set<int> visited;
set<int> :: iterator itr1,itr2;
int arr[100][100];

int addedge()
{
	int ch=0,edges=0,a=0,b=0;
	cout<<"Enter number of edges";
	cin>>edges;
	cout<<"Enter edges";
	while(edges--)
	{
			cin>>a>>b;
			adj[a].push_back(b);
			visited.insert(a);
			visited.insert(b);
	}
}

int dfs(int i)
{
	stack<int> s;
	s.push(i);
//	arr[i][i]=1;
	while(!s.empty())
	{
		int p=s.top();
		s.pop();
		arr[i][p]=1;
		for(itr=adj[p].begin();itr!=adj[p].end();itr++)
		if(arr[i][*itr]==0)
		{
			arr[i][*itr]=1;
			s.push(*itr);
		}
	}
}

int dfsdriver()
{
	for(itr1=visited.begin();itr1!=visited.end();itr1++)
		dfs(*itr1);
}

int main()
{
	addedge();
	dfsdriver();
	for(itr1=visited.begin();itr1!=visited.end();itr1++)
	{
		for(itr2=visited.begin();itr2!=visited.end();itr2++)
			cout<<arr[*itr1][*itr2]<<" ";
		cout<<endl;
	}
	return 0;
}
