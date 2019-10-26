#include<stdio.h>
#include<stdlib.h>


void warshal(int r[10][10], int n){
	int i,j,k;

	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				r[i][j] = r[i][j] || (r[i][k]&&r[k][j]);
}


void main(){
	int r[10][10],n;
	
	//Input Operation

	printf("Enter the number of vertices\n");
	scanf("%d",&n);

	printf("Enter the adjustency matrix\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&r[i][j]);
		}
	}


	//Basic Operation
		warshal(r,n);

	//Output Operation
		printf("Transitive closure is \n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d\t",r[i][j]);
			}
			printf("\n");
		}
}

	