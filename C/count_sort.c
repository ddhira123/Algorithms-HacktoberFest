#include<stdio.h>
#include<stdlib.h>

int NUM_MAX=1e3;

int main(void)
{
	int n,num;
	int count[NUM_MAX];
	scanf("%d",&n);
	int maxi=-1,mini=1e3+1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		count[num]++;
		if(num>maxi)
		{
			maxi=num;
		}
		if(num<mini)
		{
			mini=num;
		}
	}
	for(int i=mini;i<=maxi;i++)
	{
		for(int j=0;j<count[i];j++)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}