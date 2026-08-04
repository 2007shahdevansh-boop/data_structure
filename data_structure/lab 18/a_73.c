#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void insert(char a, int value)
{
    if (front == -1)
    {
        queue[++front] = value;
        rear++;
    }
    else
    {
        switch (a)
        {
        case 'l':
            if (rear == MAX - 1)
            {
                printf("queue over flow");
            }
            else
            {
                queue[++rear] = value;
            }
            break;

        case 'f':
            if (front == 0)
            {
                printf("queue over flow");
            }
            else
            {
                queue[--front] = value;
            }
            break;

        default:
            break;
        }
    }
}

void delete(char a)
{
    switch (a)
    {
    case 'l':
        if (rear == -1)
        {
            printf("queue under flow");
        }
        else if (rear == front)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            rear--;
        }
        break;

    case 'f':
        if (front == -1)
        {
            printf("queue under flow");
        }
        else if (rear == front)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front++;
        }
        break;

    default:
        break;
    }
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",queue[i]);
    }
}

int main()
{
    int choice, value;
    char pos;
    do
    {
        printf("\n-----double ended queue Operations-----\n");
        printf("1. insert an element in queue\n");
        printf("2. Display all elements.\n");
        printf("3. delete an element in stack\n");
        printf("4. Exiting.....\n");
        printf("Enter Operation = ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("enter if you want to insert from front(f) or from last(l)");
            scanf(" %c", &pos);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(pos, value);
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            printf("enter if you want to delete from front(f) or from last(l)");
            scanf(" %c", &pos);
            delete(pos);
        }
        else if (choice == 4)
        {
            printf("exiting......");
        }
        else
        {
            printf("Invalid Input");
        }
    }
        while (choice != 4);

        return 0;
    }