#include<stdio.h>
 
int main()
{
    int map1[100][100];
    int map2[100][100];
    int n,i,j;
    for(i = 0;i < 100;i++){
        for(j = 0;j < 100;j++){
            map1[i][j] = -1;
            map2[i][j] = -1;
        }
    }
    scanf("%d",&n);
    int column = 0;
    int Bsize = 0;
    int count = 0;
    int left = 0;
    for(i = 0;count != n;i++){
        for(j = 0;j <= i && count != n;j++){
            if(i % 2 == 0 && left < j){
                 left = j;
            }
            if(column < j){
                column++;
            }
            map1[i][j] = count;
            count++;
        }
    }
    Bsize = i;
    for(i = 0;i < Bsize;i++){
        for(j = 0;j < column+1;j++){
            map2[i][j] = map1[i][column-j];
        }
    }
 
    for(i = 0;i < Bsize;i++){
        for(j = column-left;j < column;j++){
            if(i % 2 == 0 && map2[i][j] >= 0){
                printf("%c",'A'+(map2[i][j]%26));
            }
            else{
                printf(" ");
            }
        }
        printf("%c",'A'+(map1[i][0]%26));
        for(j = 1;j < column+1;j++){
            if(i % 2 == 1 && map1[i][j] >= 0){
                printf("%c",'A'+(map1[i][j]%26));
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
