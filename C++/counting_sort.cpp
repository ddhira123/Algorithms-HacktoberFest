#include<bits/stdc++.h>
using namespace std;

int counting_sort(int arr[],int l,int h)
{
    int n,count[10]={0},output[100],i=0;
    n=h-l+1;
    for(i=0;i<n;i++)
    count[arr[i]]++;
    for(i=1;i<10;i++)
    count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[count[arr[i]]]=arr[i];
        count[arr[i]]--;
    }
    for(i=1;i<=9;i++)
    cout<<output[i]<<" ";
}

int main()
{
    int  arr[]={4,6,3,2,9,7,1,6,5},i=0,n=0;
    //n=sizeof(arr)/sizeof(arr[0]);
    counting_sort(arr,0,9-1);
    // for(i=1;i<=9;i++)
    // cout<<arr[i]<<" ";
    return 0;
}