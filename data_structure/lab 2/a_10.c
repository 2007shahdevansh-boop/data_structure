#include <stdio.h>
void main(){
    int i,j=0;
    printf("enter a number:");
    scanf("%d",&i);
    while (i!=0)
    {
        j=(j*10) + (i%10);
        i/=10;        
    }
       printf("reverse of the number is %d",j);
}