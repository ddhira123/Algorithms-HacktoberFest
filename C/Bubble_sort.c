#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
	{
		int a[10000],i,j,size,temp;
		printf("Enter the size of an array\n");
		scanf("%d",&size);
		clock_t start,end;
		double time_taken;
		
	//Input random nos.
		for(i=0;i<size;i++){
			a[i]=rand();
		}

		start = clock();
	//Basic Operation
		for(i=0;i<size-1;i++){
			for(j=0;j<size-i-1;j++){
				if(a[j]>a[j+1]){
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		end = clock();

		time_taken = (double)(end-start)/CLOCKS_PER_SEC;

	//Output Operation
		printf("Sorted array is as follows:\n");
			for(i=0;i<size;i++){
				printf("%d\t",a[i]);
			}

		printf("\nTime taken to execute operation is- %f",time_taken);
	}

		 
		