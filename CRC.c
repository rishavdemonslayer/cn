#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define poly_len strlen(gen_poly)
char data[64],rem[32];
char gen_poly[]="10000111";
int i,j,c,e,data_len,ch;

void xor_operation(){
    for(c=1;c<poly_len;c++){
        rem[c]=(rem[c]==gen_poly[c])?'0':'1';
    }
}

void remcal(){
    for(e=0;e<poly_len;e++){
        rem[e]=data[e];
    }
    do{
        if(rem[0]=='1'){
            xor_operation();
        }
        for(c=0;c<poly_len-1;c++){
            rem[c]=rem[c+1];
        }
        rem[c]=data[e++];
    }while(e<=data_len+poly_len-1);
}

void sender(){
    data_len=strlen(data);
    for(i=data_len;i<data_len+poly_len-1;i++){
        data[i]='0';
    }
    printf("modified data:%s\n",data);
    remcal();
    printf("reminder is:%s\n",rem);
    for(i=data_len;i<data_len+poly_len-1;i++){
        data[i]=rem[i-data_len];
    }
    printf("codeword is:%s\n",data);
}

int checkerror(){
    remcal();
    for(i=0;(i<poly_len-1)&&(rem[i]!='1');i++);
    if(i<poly_len-1){
        printf("error found....\n");
        return 1;
    }else{
        printf("no errors...\n");
        return 0;
    }
}

void receiver(){
    printf("codeword received...press 0 to check error...press 1 to introduce errors\n");
    scanf("%d",&ch);
    if(ch==0){
        checkerror();
    }
    else if(ch==1){
        printf("enter the position of error\n");
        scanf("%d",&i);
        while(i>=0&&i<data_len+poly_len-1){
            data[i-1]=(data[i-1]=='0')?'1':'0';
            printf("to introduce more errors press1\n");
            scanf("%d",&ch);
            if(ch==1){
                scanf("%d",&i);
            }
            else{
                break;
                }
        }
    }
        printf("new data:%s",data);
        checkerror();    
}

int main(){
    int data_size;
    printf("enter the size of data:");
    scanf("%d",&data_size);
    printf("enter the data:");
    scanf("%s",data);
    sender();
    receiver();
    return 0;
}