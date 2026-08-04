#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];

struct node{
    int info;
    struct node* next; 
};

struct node* top=NULL;

void push(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));

    newnode->info=value;
    if(top==NULL){
        newnode->next=NULL;
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

void pop(){
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        printf("element popped is %d",top->info);
        top=top->next;
    }
}


void display(){
    struct node* newnode=top;

    if(top==NULL){
        printf("stack is empty");
    }
    else{
        while(newnode==NULL){
            printf("%d",newnode->info);
            newnode=newnode->next;
        }

        printf("NULL\n");
    }
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK OPERATIONS (LINKED LIST) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}