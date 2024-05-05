#include <stdio.h>
#include <stdlib.h>
int main(int argc,char** argv){
    int array[50],parity,i,size;
    printf("enter the size of input stream:");
    scanf("%d",&size);
    printf("enter the input bit stream:");
    for(i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    printf("the input bit stream is:");
    for(i=0;i<size;i++){
        printf("%d",array[i]);
    }
    printf("\n");
    int count=0;
    for(i=0;i<size;i++){
        if(array[i]==1){
            count++;
        }
    }
    if(count%2==0){
        parity=0;
    }
    else{
        parity=1;
    }
    printf("\n thus the parity bit is: %d\n",parity);
    printf("the final output bit stream is:");
    for(i=0;i<size;i++){
        printf("%d",array[i]);
    }
    printf("%d",parity);
}