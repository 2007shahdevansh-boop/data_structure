#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};

struct node* first=NULL;

int get_count() {
    int count = 0;
    struct node* current = first;

    while (current != NULL) {
        count++;
        current = current->link; 
    }

    return count;
}    

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

void swap(int k, int count) {
    if (k < 1 || k > count || k == count - k + 1) {
        return; 
    }

    struct node* prev1 = NULL;
    struct node* curr1 = first;
    for (int i = 1; i < k; i++) {
        prev1 = curr1;
        curr1 = curr1->link;
    }

    struct node* prev2 = NULL;
    struct node* curr2 = first;
    for (int i = 1; i < count - k + 1; i++) {
        prev2 = curr2;
        curr2 = curr2->link;
    }

    if (prev1 != NULL) {
        prev1->link = curr2;
    } else {
        first = curr2; 
    }

    if (prev2 != NULL) {
        prev2->link = curr1;
    } else {
        first = curr1; 
    }

    if (curr1->link == curr2) {
        curr1->link = curr2->link;
        curr2->link = curr1;
    } else if (curr2->link == curr1) {
        curr2->link = curr1->link;
        curr1->link = curr2;
    } 
    else {
        struct node* temp = curr1->link;
        curr1->link = curr2->link;
        curr2->link = temp;
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
    
    printf("enter which position from start and end you want to swap");
    scanf("%d",&k);
    count=get_count();
    swap(k,count);

    printf("Data in swapped linked list: ");
    display(); 
}