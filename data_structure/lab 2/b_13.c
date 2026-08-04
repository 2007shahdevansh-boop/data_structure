#include<stdio.h>
void main(){
    int a,b,i;
    printf("enter a first interval:");    
    scanf("%d",&a);
    printf("enter a second interval:");    
    scanf("%d",&b);
    printf("prime numbers in the giver interval is:");
    i=a;
    while (i!=b){
        for (int j = 2; j < i; j++)
        {
            if(i%j==0){
                goto x;
            }
        }
        printf("%d \n",i);
        x:
        i++;
    }
    
}