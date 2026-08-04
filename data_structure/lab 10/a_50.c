#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};

struct node* first=NULL;

int insert(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    
    newnode->info = value;
    newnode->link = NULL; 
    if (first == NULL) {
        first = newnode;
        return 0;
    }

    struct node *temp = first;
    while (temp->link != NULL) {
        temp = temp->link;
    }

    temp->link = newnode;

    return 0;
}

void display() {
    struct node *temp = first; 
    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

void swap() {
    struct node* prev = NULL;
    struct node* curr = first;
    struct node* nextNode = NULL;

    first = curr->link;

    while (curr != NULL && curr->link != NULL) {
        nextNode = curr->link;
        curr->link = nextNode->link;
        nextNode->link = curr;
        if (prev != NULL) {
            prev->link = nextNode;
        }
        prev = curr;
        curr = curr->link; 
    }
}

void main(){
    int value, choice,k;
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

    swap();

    printf("Data in linked list with swapped no.: ");
    display(); 
}