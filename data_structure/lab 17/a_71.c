#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int info;
    struct node* link; 
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int a){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=a;
    newnode->link=NULL;

    if(front==NULL){
        front=newnode;
        rear=front;
    }
    else{
        rear->link=newnode;
        rear=newnode;
    }
}

int dequeue(){
    if(front==NULL){
        printf("queue underflow");
        return -1;
    }
    else if(front==rear){
        int y=front->info;
        front=NULL;
        rear=NULL;
        return y;
    }
    else{
        int y = front->info;
        front=front->link;
        return y;
    }
}

void display(){
    struct node* save=front;
    if(save==NULL){
        printf("queue is empty");
        return;
    }
    while(save->link!=NULL){
        printf("%d ->",save->info);
        save=save->link;
    }
    printf("%d",save->info);
}
int main(){
int choice,value;
    do{
        printf("\n-----queue Operations-----\n");
        printf("1. enqueue an element in queue\n");
        printf("2. Display all elements.\n");
        printf("3. dequeue an element in stack\n");
        printf("4. Exiting.....\n");
        printf("Enter Operation = ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2 :
                display();
                break;
            case 3 :
                printf("the element %d is popped",dequeue());
                break;
            case 4 : 
                printf("exiting......");
                break; 
            default :
                printf("Invalid Input");
        }
    }
    while(choice!=4);

    return 0;
}