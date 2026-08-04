
#include <stdio.h>
int fact(int a){
    if(a==0||a==1){
        return 1;
    }
    else{
        return a*fact(a-1);
    }
}
void main() {
int a;
printf("enter a number:");
scanf("%d",&a);
int ans = fact(a);
printf("factorial of the number is %d",ans);
}
