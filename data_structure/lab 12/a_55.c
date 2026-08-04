#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *first = NULL;

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

void alternate()
{
    struct node *curr = first;

    while (curr != NULL && curr->next != NULL)
    {
        struct node *node1 = curr;
        struct node *node2 = curr->next;

        if (node1->prev != NULL)
            node1->prev->next = node2;
        else
            first = node2;

        if (node2->next != NULL)
            node2->next->prev = node1;

        node1->next = node2->next;
        node2->prev = node1->prev;

        node2->next = node1;
        node1->prev = node2;

        curr = node1->next;
    }
}

void main(){
    int pos,value,choice;

    do
    {
        printf("Enter info = ");
        scanf("%d", &value);
        insertAtLast(value);
        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Data in doubly linked list: ");
    display();


    alternate();

    printf("Data in swapped linked list:");
    display(); 
}