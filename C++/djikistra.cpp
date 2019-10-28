//djikistra algo for single source shortest path	greedy
//run in ideone
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int weight;
	bool visit;
};

vector< pair<int,int> > adj[100];
vector<pair<int,int> > :: iterator itr;
map<int,node> visited;
set<int> s;
set<int> ::iterator it,it1;


int addedge()
{
	int a=0,b=0,c=0,i=0,j=0,ch=0,n=0;
	cout<<"Enter directed(1)/undirected(2)";
	cin>>ch;
	cout<<"Enter number of edges";
	cin>>n;
	cout<<"Enter start node, end node and weight";
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(b,c));
		if(ch==2)
		adj[b].push_back(make_pair(a,c));
		visited[a].weight=INT_MAX;
		visited[b].weight=INT_MAX;
		visited[a].visit=false;
		visited[b].visit=false;
	}
}

//auto comp = [](pair<int,int> a, pair<int,int> b) { return (a.second) < (b.second); };

int djikistra(int i)
{

//	priority_queue <pair<int,int>,vector<pair<int,int> >,decltype(comp)> q(comp);
	visited[i].weight=0;
	visited[i].visit=true;
	int temp=i;
	s.insert(temp);
//	q.push(make_pair(i,0));
	while(!s.empty())
	{
		int wt=INT_MAX;
		for(it=s.begin();it!=s.end();it++)
		if(wt>visited[*it].weight)
		{it1=it;wt=visited[*it].weight;}
		visited[*it1].visit=true;
		temp=*it1;
		int p=visited[*it1].weight;
		 //cout<<"#"<<*it1;
		s.erase(it1);
		
		for(itr=adj[temp].begin();itr!=adj[temp].end();itr++)
		{
			auto a=*itr;
			//cout<<"#"<<a.first;
			if(!visited[a.first].visit)
			{
				visited[a.first].weight=min(visited[a.first].weight,p+(a.second));
				s.insert(a.first);
			}
		}
		//temp=q.top().first;
	}
}


int main()
{
	int i=0;
	addedge();
	cout<<"Enter starting node";
	cin>>i;
	djikistra(i);
	for(auto it=visited.begin();it!=visited.end();it++)
	cout<<it->first<<" "<< (it->second).weight <<"\n";
	return 0;
}
