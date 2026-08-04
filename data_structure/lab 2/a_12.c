#include<stdio.h>
void main(){
    int a,count=0;
    printf("enter a number:");    
    scanf("%d",&a);
    for (int i = 2; i < a; i++)
    {
        if(a%i==0){
            printf("not prime");
            break;
        }
        count++;
    }
    if(count>0){
        printf("prime");
    }
}