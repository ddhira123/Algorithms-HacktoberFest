#include<stdio.h>
void bsearch(int arr[],int n,int i)
{
    int mid,min=0,max=n-1,f=0;

    while(min<=max)
    {
        mid=(min+max)/2;
        if(arr[mid]>i);
        {
            max=mid-1;
        }
        else if(arr[mid]<i)
        {
            min=mid+1;
        }
        else if (arr[mid]==i)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        printf("FOUND");
    else
        printf("NOT FOUND");
}
void main()
{
    int n=5;
    int arr[n],i,f;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    printf("ENTER ELEMENT TO SEARCH\n");
    scanf("%d",&f);
    bsearch(arr,n,f);

}
