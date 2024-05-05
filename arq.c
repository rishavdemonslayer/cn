#include<stdio.h>
#include<stdlib.h>
void StopAndWait();
void GoBackN();
void Selective();
int main(int argc, char** argv) {
    int val;
    while(1){
        printf("\nEnter your choice: \n 1.Stop And Wait protocol\n" "2.Go back N\n 3.Selectiverepeat\n");
        scanf("%d", &val);
        switch(val) {
            case 1: StopAndWait();
            break;
            case 2: GoBackN();
            break;
            case 3: Selective();
            break;
            default: return(0);
        }
    }    
return (EXIT_SUCCESS);
}

void StopAndWait(){
    int n,i=0, frame;
    printf("Enter the total number of frames : ");
    scanf("%d", &n);
    while (i!=n) {
        printf("\nEnter received frame : ");
        scanf("%d", &frame);
        if (frame==i+1){
            printf("Transmitting....ACK to frame %d\n", frame);
        i++;
        }
        else{
            printf("Negative ACK.... to frame %d\n",i+1);
        }
    }
}        

void GoBackN(){
    int n,i=0, frame, size,t;
    printf("Enter the total number of frames: "); 
    scanf("%d", &n);
    printf("Enter window size of frames: ");
    scanf("%d", &size);
    printf("Sending frames "); 
    for (int j=0;j<size;j++){ 
        printf("%d ", j+1);
    }
    for (int j=0;j<n;j++){
        printf("\n Is frame %d is received (1 or 0): ",j+1); 
        scanf("%d", &t);
        if(t==1){
            printf("\n Sending ACK to frame %d\n sliding window", j+1); 
            printf("\n In window: ");
            for(int k=j+1;k<j+1+size; k++){
                if (k<n)
                    printf("%d ",k+1);
            }
        }
        else{
            printf("\n Retransmitting frames \t");
            for(int m=j;m<j+size;m++){
            if (m<n)
            printf("%d ",m+1);
            }
        j--;
        }
    }

}

void Selective() {
    int n,i=0, frame, m, size;
    printf("Enter the total number of frames: ");
    scanf("%d", &n);
    printf("Sending frames ");
    for (int j=0;j<n;j++){
        printf("%d ", j+1);
    }
    printf("\nEnter the number of frames received: \n");
    scanf("%d", &m);
    int a[n];
    printf("\nEnter received frame : \n");
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    int trigger=0;
    for (int i=0;i<n;i++) { 
        trigger=0;
        for(int j=0;j<m;j++){ 
            if((i+1==a[j])){ 
                trigger=1;
            }
        }
    if (trigger==0){
        printf("Retransmitting frame %d\n",i+1);
        a[m++]=i+1;
        }
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(a[i]<a[j]){ 
                int temp=a[i]; 
                a[i]=a[j];
                a[j]=temp; }} }
    printf("\nSorting ");
    for (int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
}