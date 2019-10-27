#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int l,int r,int mid)
{
    int l1=0,l2=0,i=0,j=0,k=0,arr1[100],arr2[100];
    l1=mid-l+1;
    l2=r-mid;
    for(i=l,k=0;i<=mid;i++,k++)
    arr1[k]=arr[i];
    for(i=mid+1,k=0;i<=r;i++,k++)
    arr2[k]=arr[i];
    i=0,j=0,k=l;
    while(i<l1&&j<l2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    for(;i<l1;i++,k++)
    arr[k]=arr1[i];
    for(;j<l2;j++,k++)
    arr[k]=arr2[j];
}

int merge_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}

int main()
{
    int  arr[]={4,6,3,2,9,7,1,6,5},i=0,n=0;
    //n=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,9-1);
    for(i=0;i<9;i++)
    cout<<arr[i]<<" ";
    return 0;
}