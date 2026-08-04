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



void sort() {

    int flag;
    do {
        flag = 0;
        struct node* prev = NULL;
        struct node* current = first;

        while (current->link != NULL) {
            struct node* nextnode = current->link;

            if (current->info > nextnode->info) {
                flag = 1;

                current->link = nextnode->link;
                nextnode->link = current;

                if (prev == NULL) {
                    first = nextnode; 
                } else {
                    prev->link = nextnode; 
                }

                prev = nextnode;
            } else {
                prev = current;
                current = current->link;
            }
        }
    } while (flag != 0);
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
        insert(value);
        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Data in linked list: ");
    printList(); 

    sort();

    printf("Data in sorted linked list: ");
    printList(); 
}