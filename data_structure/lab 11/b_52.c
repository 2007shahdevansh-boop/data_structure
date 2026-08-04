#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};

struct node* first=NULL;
struct node* last=NULL;
struct node* first1=NULL;
struct node* last1=NULL;

void insert(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=value;
    if(first==NULL || last==NULL){
        newnode->link=newnode;
        first=newnode;
        last=newnode;
    }
    else{
        newnode->link=first;
        last->link=newnode;
        last=newnode;
    }
}

void display(){
    struct node* dis=first;
    struct node* dis2=first1;
    do
    {
        printf("%d ->",dis->info);
        dis=dis->link;
    } while (dis != last);
    printf("%d \n",dis->info);
    
    if(first1!=NULL){
        do
    {
        printf("%d ->",dis2->info);
        dis2=dis2->link;
    } while (dis2 != last1);
    printf("%d",dis2->info);
    }
}

void split(int k){
    struct node* prev=last;
    struct node* curr=first;

    for(int i=0;i<k-1;i++){
        prev=prev->link;
        curr=curr->link;
    }
    prev->link=first;
    last->link=curr;
    last1=last;
    first1=curr;
    last=prev;
}

void main(){
    int pos,value,choice;

    do
    {
        printf("Enter info = ");
        scanf("%d", &value);
        insert(value);
        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Data in linked list: ");
    display();

    printf("\nenter position to split the linked list:");
    scanf("%d",&pos);

    split(pos);

    printf("Data in splitted linked list:");
    display(); 
}