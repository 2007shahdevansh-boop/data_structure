#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *first = NULL;

void insertAtFirst(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->info = x;
    newnode->prev = NULL;


    if (first == NULL)
    {
        newnode->next = NULL;
        first = newnode;
    }
    else
    {
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }
    
}

void insertAtLast(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;

    if (first == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        first = newnode;
    }
    else
    {
        struct node *save = first;
        while (save->next != NULL)
        {
            save = save->next;
        }
        save->next = newnode;
        newnode->next = NULL;
        newnode->prev = save;
    }
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *save = first;

    while (save->next != NULL)
    {
        printf("%d ->", save->info);
        save = save->next;
    }

    printf("%d", save->info);
}

void delete(int k)
{
    struct node *save = first;

    for (int i = 1; i < k; i++)
    {
        if (save == NULL)
        {
            printf("invalid pos.");
            return;
        }
        save = save->next;
    }
    if (save == NULL)
        {
            printf("invalid pos.");
            return;
        }
    if(save->next==NULL && save->prev==NULL){
        first=NULL;
    }    
    else if (save->prev == NULL)
    {
        save->next->prev = NULL;
        first = save->next;
    }
    else if(save->next==NULL){
        save->prev->next=NULL;
    }
    else
    {
        save->prev->next = save->next;
        save->next->prev = save->prev;
    }

    free(save);
}

void main()
{
    int choice, value, pos;
    do
    {
        printf("\n-----doubly Linked List Operations-----\n");
        printf("1. Insert a node at the front of the linked list.\n");
        printf("2. Display all nodes.\n");
        printf("3. Delete a node at certain position of the linked list.\n");
        printf("4. Insert a node at the end of the linked list.\n");
        printf("5. Exiting.....\n");
        printf("Enter Operation = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtFirst(value);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete(pos);
            break;
        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtLast(value);
            break;
        case 5:
            printf("Exit....\n");
            break;

        default:
            printf("Invalid Input");
        }
    } while (choice != 5);
}