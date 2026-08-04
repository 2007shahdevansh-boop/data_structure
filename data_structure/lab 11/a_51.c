#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};

struct node* first=NULL;
struct node* last=NULL;

void insertAtFirst(int value){
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
        first=newnode;
    }
}

void insertAtEnd(int value){
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
    do
    {
        printf("%d ->",dis->info);
        dis=dis->link;
    } while (dis != last);
    printf("%d",dis->info);
}

void delete(int k){
    struct node* curr=first;
    struct node* prev=last;
    for (int i = 1; i < k; i++)
    {
        curr=curr->link;
        prev=prev->link;
    }
    prev->link=curr->link;
    prev=prev->link;
    curr=prev->link;
}

void main(){
    int choice,value,pos;
    do{
        printf("\n-----circular Linked List Operations-----\n");
        printf("1. Insert a node at the front of the linked list.\n");
        printf("2. Display all nodes.\n");
        printf("3. Delete a node at certain position of the linked list.\n");
        printf("4. Insert a node at the end of the linked list.\n");
        printf("5. Exiting.....\n");
        printf("Enter Operation = ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtFirst(value);
                break;
            case 2 :
                display();
                break;
            case 3 :
                printf("Enter position: ");
                scanf("%d", &pos);
                delete(pos);
                break;
            case 4 : 
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break; 
            case 5 :
                printf("Exit....\n");
                break;
                
            default :
                printf("Invalid Input");
        }
    }
    while(choice!=5);
}