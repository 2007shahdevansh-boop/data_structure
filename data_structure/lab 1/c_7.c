
#include <stdio.h>
void main() {
int a,y,w,d;
printf("enter total days:");
scanf("%d",&a);
y=a/365;
a-=y*365;
w=a/7;
a-=w*7;
d=a;
printf("your time is %d : %d : %d",y,w,d);
}