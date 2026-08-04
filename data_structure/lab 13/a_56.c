#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top=-1;



void push(int value){
    if(top==MAX-1){
        printf("stack overflow....");
        return;
    }
    stack[++top]=value;
}

int pop(){

    if(top==-1){
        printf("stack is empty....");
        return -1;
    }

    return stack[top--];
}

void display(){

    if(top==-1){
        printf("stack is empty");
    }

    for(int i=0;i<top;i++){
        printf("%d ->",stack[i++]);
    }

     printf("%d",stack[i]);
}

int peek(int i){

    if(i>=MAX || i<0){
        printf("invalid position");
    }

    return stack[top-i+1];
}

void change(int i,int value){
    if(top==-1){
        printf("stack is empty...");
    }
    else if(i>=MAX || i<0){
        printf("invalid position");
    }
    else{
        stack[top-i+1]=value;
    }
}

void main(){
    
    int choice,value,pos;
    do{
        printf("\n-----Stack Operations-----\n");
        printf("1. push an element in stack\n");
        printf("2. Display all elements.\n");
        printf("3. pop an element in stack\n");
        printf("4. peek an element\n");
        printf("5. change an element\n");
        printf("6. Exiting.....\n");
        printf("Enter Operation = ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2 :
                display();
                break;
            case 3 :
                printf("the element %d is popped",pop());
                break;
            case 4 : 
                printf("Enter position: ");
                scanf("%d", &value);
                printf("the element at that position is %d",peek(value));
                break; 
            case 5 :
                printf("Enter position and value respectively: ");
                scanf("%d %d",&value,&pos);
                change(pos,value);
                break; 
            
            case 6 : 
                printf("exiting......");
                break;
            default :
                printf("Invalid Input");
        }
    }
    while(choice!=6);
}
