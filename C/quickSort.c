#include<stdio.h>
#include<stdlib.h>

void quickSort(int *arr,int l,int r){
	if(l >= r) return;
	int cur = 0, done = 0, tem;
	while(l + cur < r){
	 	if(arr[l + cur] >= arr[r]) cur++;
	 	else if(cur != done) tem = arr[l + done], arr[l + done] = arr[l + cur], arr[l + cur] = tem, cur++, done++;
	 	else cur++, done++;
	}
	if(l+done != r)	tem = arr[l + done], arr[l + done] = arr[r], arr[r] = tem;
	quickSort(arr, l, l+cur-1);
	quickSort(arr, l+cur+1, r);
}
int main(){
	int n,i,*arr;
	scanf("%d\n",&n);
	arr = (int *)malloc(sizeof(int)*n);
	for(i = 0 ; i < n; i++) scanf("%d",arr+i);
	quickSort(arr, 0, n-1);
	for(i = 0; i < n; i++) printf("%d ",arr[i]);
	free(arr);
	return 0;
}
