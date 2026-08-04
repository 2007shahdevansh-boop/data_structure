#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *link;
};
struct Node *start = NULL;
void removeDuplicates(){
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while(ptr1 != NULL && ptr1->link != NULL){
        ptr2 = ptr1;
        while(ptr2->link != NULL){
            if(ptr1->info == ptr2->link->info){
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
            }
            else{
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
    }
}
void display(){
    struct Node *ptr = start;
    while(ptr != NULL){
        printf("%d -> ", ptr->info);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
void insert(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->link = NULL;
    if(start == NULL){
        start = newNode;
        return;
    }
    struct Node *ptr = start;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = newNode;
}
void main(){
    int choice, value;
    do{
        printf("1. Insert\n2. Display\n3. Remove Duplicates\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                removeDuplicates();
                printf("Duplicates removed.\n");
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 4);
}
