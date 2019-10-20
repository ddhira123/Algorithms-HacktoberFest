#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> &x,pair<int,int> &y)
{
	if(x.second <= y.second)
		return 1;
	else
		return 0;
}

int main()
{
	
	int n;
	cin>>n;
	vector<pair<int,int> > event;
	cout<<"Enter the starting and ending times for "<<n<<"Events"<<endl;
	for(int i=0;i<n;i++)
	{
		int start,end;
		cin>>start>>end;
		event.push_back(make_pair(start,end));
	}
	
	sort(event.begin(),event.end(),comp);
	vector<pair<int,int> >::iterator it;
	
		for(it=event.begin();it!=event.end();it++)
		{
			cout<<it->first<<" "<<it->second<<endl;
		}
		int k=0,count=1;
		cout<<"interval"<<event[0].first<<" "<<event[0].second;
		for(int i=1;i<event.size();i++)
		{
			if(event[i].first >= event[k].second)
			{
				cout<<"interval"<<event[i].first<<" "<<event[i].second<<endl;
				k=i;
				count++;
			}
		}
		cout<<"Total no of non overlapping intervals are"<<count<<endl;
		
}