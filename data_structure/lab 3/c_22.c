#include<stdio.h>
void main(){
    int a;
    printf("enter at how many ines you want to print the pattern:");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        for(int s=0;s<=a-i-1;s++){
            printf(" ");
        }
        long num=1;
        for(int j=0;j<=i;j++){
            printf("%4ld",num);
            num=num*(i-j)/(j+1);
        }
        printf("\n");
    }
}