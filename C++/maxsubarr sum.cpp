#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; } 
  
// A utility funtion to find maximum of three integers 
int max(int a, int b, int c) { return max(max(a, b), c); } 
int maxcross(int arr[],int l,int r)
{
    int mid=l+(r-l)/2;
    int s=0,smax=INT_MIN,smax1=INT_MIN,i=0;
    for(i=mid;i>=l;i--)
    {
        s+=arr[i];
        if(s>smax)
        smax=s;
    }
    s=0;
    for(i=mid+1;i<=r;i++)
    {
        s+=arr[i];
        if(s>smax1)
        smax1=s;
    }
    return smax+smax1;
}

int maxsub(int arr[],int l,int r)
{
    if(l==r)return arr[l];
    int mid=l+(r-l)/2;
    return max(maxsub(arr,l,mid),maxsub(arr,mid+1,r),maxcross(arr,l,r));
}

int main()
{
    int arr[] = {2, 3, 4, 5, 7};
    cout<<maxsub(arr,0,4);
}