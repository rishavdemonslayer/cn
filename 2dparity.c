#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j,row,col,array[10][10];
    int count=0;
    printf("enter the no. of rows");
    scanf("%d",&row);
    printf("enter the no. of cols");
    scanf("%d",&col);
    printf("enter the input bit stream:");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&array[i][j]);
        }
    }
    printf("\nthe input bit stream is:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d",array[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(array[i][j]==1){
                count++;
            }
            if (count%2==0){
                array[i][col]=0;
            }
            else{
                array[i][col]=1;
            }
        }
        count=0;
    }
    for(j=0;j<col;j++){
        for(i=0;i<row;i++){
            if(array[i][j]==1){
                count++;
            }
            if (count%2==0){
                array[row][j]=0;
            }
            else{
                array[row][j]=1;
            }
        }
        count=0;
    }
    printf("the output bit stream is:\n");
    for(i=0;i<=row;i++){
        for(j=0;j<=col;j++){
            printf("%d",array[i][j]);
        }
        printf("\n");
    }

    return 0;
}