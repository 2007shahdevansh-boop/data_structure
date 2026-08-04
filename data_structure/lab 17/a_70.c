#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int a){
    if(rear==MAX-1){
        printf("queue overflow.");
        return;
    }
    if(rear==-1){
        queue[++front]=a;
        ++rear;
    }
    else{
        queue[++rear]=a;
    }
}

int dequeue(){
    if(front==-1){
        printf("queue underflow");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        return queue[front++];
    }
}

void display(){
    int a=front;
    if(front==-1){
        printf("queue is empty");
        return;
    }
    for(a=front ; a<rear ; a++){
        printf("%d ->",queue[a]);
    }
    printf("%d",queue[a]);
}
void main(){
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
}