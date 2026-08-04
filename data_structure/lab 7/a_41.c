#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
int main(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));


    printf("Enter info = ");
    scanf("%d",&newnode->info);


    newnode->link = first;
    first=newnode;

    printf("Data in node = %d\n", newnode->info);
    free(newnode);
return 0;
}