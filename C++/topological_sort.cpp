#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cout<<"Enter the no of vertices\n";
cin>>n;
int a[n][n],sum,i,j,indegree[10],job[10],z;

cout<<"Enter the adjacency matrix\n";
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
cin>>a[i][j];


int count=0;

while(count<n)
{
for(i=1;i<=n;i++)
{
	sum=0;
if(indegree[i]!=-1)
{
for(j=1;j<=n;j++)
{
sum=sum+a[j][i];
}
indegree[i]=sum;

}
}

int flag=0;
for(i=1;i<=n;i++)
{
if(indegree[i]==0){
flag=1;
z=i;
break;
}
}
if(flag==0)
{
cout<<"Cant perform toposorting\n";
}
for(j=1;j<=n;j++)
a[z][j]=0;
indegree[z]=-1;
job[count]=z+1;
count++;
}
for(i=1;i<=n;i++)
	cout<<job[i]<<" ";
}






