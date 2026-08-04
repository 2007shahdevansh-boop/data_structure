#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

int insert_at_last(int value)
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

int reverse(){
    struct node *prev = NULL;
    struct node *curr = first;
    struct node *next = NULL;

    while (curr != NULL)
    {
        next = curr->link;  
        curr->link = prev;  
        prev = curr;        
        curr = next;        
    }
    first = prev; 
    return 0;
}

void printList() {
    struct node *temp = first; 
    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

void main(){
    int value, choice;
    do
    {
        printf("Enter info = ");
        scanf("%d", &value);
        insert_at_last(value);
        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    reverse();

    printf("Data in reversed linked list: ");
    printList(); 


    
}