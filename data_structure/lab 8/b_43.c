#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *first1=NULL;
struct node *first2=NULL;

void insert1(int value1){
    struct node *newNode1 = (struct node *)malloc(sizeof(struct node));
    newNode1->info=value1;
    newNode1->link=first1;
    first1=newNode1;
}
void insert2(int value2){
    struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode2->info=value2;
    newnode2->link=first2;
    first2=newnode2; 
}
int main(){
    struct node *newnode1= (struct node *)malloc(sizeof(struct node));
    struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
    int a,b,value1,value2;
    do {
    printf("enter 1 to add value of first node enter 2 to end:\n");
    scanf("%d",&a);
    switch(a){
        case 1:
         printf("Enter value: ");
         scanf("%d", &value1);
         insert1(value1);
         break;

        case 2:
         break;        
    }
}
while(a!=2);
do {
    printf("enter 1 to add value of second node enter 2 to end:\n");
    
    scanf("%d",&b);
    switch(b){
        case 1:
         printf("Enter value: ");
         scanf("%d", &value2);
         insert2(value2);
         break;

        case 2:
        break;        
    }
}
while(b!=2);

if(sizeof(newnode1)!=sizeof(newnode2)){
    printf("not similar");
    return 0; 
}
struct node *save1=first1;
struct node *save2=first2;
while(save1->link!=NULL){
    if(save1->info!=save2->info){
        printf("not similar");
        return 0;
    }
    save1=save1->link;
    save2=save2->link;
}
printf("similar");
return 0;
}