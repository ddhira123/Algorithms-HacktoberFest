#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int low,int mid,int high){
	int i,j,k,*arr1,*arr2;
	i = j = k = 0;
	arr1 = (int *)malloc(sizeof(int)*(mid-low+1));
	arr2 = (int *)malloc(sizeof(int)*(high-mid));
	while(i++ < mid-low+1) arr1[i-1] = arr[low+i-1]; 
	while(j++ < high - mid) arr2[j-1] = arr[mid+j]; 
	i = j = 0;
	while(i < mid-low+1 && j < high - mid)
		if(arr1[i] < arr2[j]) arr[low + k] = arr1[i],i++,k++;
		else arr[low + k] = arr2[j],j++,k++;
	if(i == mid-low+1) 
		while(j != high - mid) arr[low + k] = arr2[j] ,j++ ,k++;
	else 
		while(i != mid-low+1) arr[low + k] = arr1[i] ,i++ ,k++;
	free(arr1);
	free(arr2);
}

void mergeSort(int *arr,int low,int high){
	if(low == high) return;
	int mid = (low + high )/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}

int main(){
    int n,*arr,i;
    scanf("%d\n",&n);
    arr = (int *)malloc(sizeof(int) *n);
    for(i = 0; i < n; i++) scanf("%d",arr+i);
    mergeSort(arr,0,n-1);
    for(i = 0; i < n; i++) printf("%d ",arr[i]);
    free(arr);
    return 0;
}