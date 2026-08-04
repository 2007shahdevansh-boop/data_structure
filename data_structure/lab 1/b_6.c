
#include <stdio.h>
void main() {
int a,h,m,s;
printf("enter total seconds:");
scanf("%d",&a);
h=a/3600;
a-=h*3600;
m=a/60;
a-=m*60;
s=a;
printf("your time is %d : %d : %d",h,m,s);
}