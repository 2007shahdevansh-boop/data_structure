
#include <stdio.h>

void main() {
int p,n,ans=1;
printf("enter power and number respectively : \n");
scanf("%d %d",&p,&n);
for(int i=1;i<=p;i++){
    ans*=n;
}
printf("the answer is %d",ans);
}
