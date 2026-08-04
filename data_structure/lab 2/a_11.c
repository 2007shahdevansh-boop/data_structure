#include<stdio.h>
void main(){
    int a;
    printf("enter a number:");
    scanf("%d",&a);
    printf("factors of the number you entered are:");
    for (int i = 1; i <= a; i++)
    {
        if (a%i==0)
        {
            printf("%d \n",i);
        }
        
    }
    
}