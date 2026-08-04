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

int GCD(int x,int y){
    int gcd=1;
    int min=(x<y)?x:y;
    for(int i=1;i<=min;i++){
        if(x%i==0 && y%i==0){
            gcd=i;
        }
    }
    return gcd;
}

void insert_gcd(){
    struct node* prev=first;
    struct node* next=first->link;

    while(next != NULL){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=GCD(prev->info,next->info);
        newnode->link=next;
        prev->link=newnode;
        prev=next;
        next=next->link;
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

    insert_gcd();

    printf("Data in linked list with gcd between: ");
    display(); 
}