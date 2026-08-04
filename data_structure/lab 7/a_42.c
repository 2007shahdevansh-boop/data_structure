#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *link;
};
struct Node *first = NULL;
void insertFront(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info=value;
    newNode->link=first;
    first=newNode;
}
void insertEnd(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *save = first;
    newNode->info=value;
    newNode->link=NULL;
    if(first==NULL){
        first=newNode;
        return;
    }
    while(save->link!=NULL){
        save = save->link;
    }
    save->link=newNode;
}
void insertPosition(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    if(first==NULL){
        newNode->link = NULL;
        first = newNode;
    }
    if(newNode->info <= first->info){
        newNode->link = first;
        first = newNode;
    }
    struct Node *save = first;
    while(save->link != NULL && newNode->info >= save->info){
        save = save->link;
    }
    newNode->link = save->link;
    save->link = newNode;
}
void display(){
    struct Node *save = first;
    if(first == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Linked List : ");
    while(save != NULL){
        printf("%d -> ",save->info);
        save = save->link;
    }
    printf("NULL\n");
}
void deleteFront(){
    if(first == NULL){
        printf("Link is Empty.\n");
        return;
    }
    struct Node *save = first;
    first = first->link;
    free(save);
    printf("First node deleted.\n");
}
void deleteEnd(){
    if(first == NULL){
        printf("Link is Empty.\n");
        return;
    }
    if(first->link == NULL){
        free(first);
        first=NULL;
        printf("Last node deleted.\n");
    }
    struct Node *save = first;
    while(save->link != NULL){
        save = save->link;
    }
    free(save->link);
    printf("Last node deleted.\n");
}
void deletePosition(int pos){
    if(first == NULL){
        printf("Link is Empty.\n");
        return;
    }
    if(pos==1){
        deleteFront();
        return;
    }
    struct Node *save = first;
    struct Node *pred = NULL;
    int i;
    for(i=1;i<pos && save != NULL ;i++){
        pred=save;
        save=save->link;
    }
    if(save == NULL){
        printf("Invalid Position\n");
        return;
    }
    pred->link=save->link;
    free(save);
    printf("Node deleted from position %d\n", pos);
}
int countnodes(){
    int count = 0;
    struct Node *save = first;
    while(save != NULL){
        count++;
        save = save->link;
    }
    return count;
}
int main(){
    int choice,value,pos;
    do{
        printf("\n-----Singly Linked List Operations-----\n");
        printf("1. Insert a node at the front of the linked list.\n");
        printf("2. Display all nodes.\n");
        printf("3. Delete a first node of the linked list.\n");
        printf("4. Insert a node at the end of the linked list.\n");
        printf("5. Delete a last node of the linked list.\n");
        printf("6. Delete a node from specified position.\n");
        printf("7. Count the no. of nodes in the linked list.\n");
        printf("8. Insert a node from specified position.\n");
        printf("9. Exiting.....\n");
        printf("Enter Operation = ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2 :
                display();
                break;
            case 3 :
                deleteFront();
                break;
            case 4 : 
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break; 
            case 5 :
                deleteEnd();
                break;
            case 6 :
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            case 7 :
                printf("Number of nodes = %d\n",countnodes());
                break;
            case 8 :
                printf("Enter value: ");
                scanf("%d", &value);
                insertPosition(value);
                break;
            case 9 :
                printf("Exit....\n");
                break;
            default :
                printf("Invalid Input");
        }
    }
    while(choice!=9);
    return 0;
}