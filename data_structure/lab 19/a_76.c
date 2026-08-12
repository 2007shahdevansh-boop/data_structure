#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* right;
    struct node* left;
};

struct node* createnode(int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->info=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* insert(struct node* save,int key){

    if(save == NULL){
        save = createnode(key);
        return save;
    }

    if(save->info == key){
        printf("duplicate not allowed");
        return save;
    }

    if(key < save->info){
        save->left = insert(save->left,key);
        return save;
    }
    else{
        save->right = insert(save->right,key);
        return save;
    }

    return save;
}

struct node* sameTree(struct node* root1,struct node* root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }

    if(root1 == NULL || root2 == NULL){
        return 0;
    }

    if(root1->info != root2->info){
        return 0;
    }

    return sameTree(root1->left,root2->left) && sameTree(root1->right,root2->right);
}

int main()
{
    // Banne tree na root pointers initialize karo NULL sathe
    struct Node *root1 = NULL;
    struct Node *root2 = NULL;

    int n1, n2, info, i;

    // Pehla tree mate node count scan karo
    printf("Enter number of nodes for first tree: ");
    scanf("%d", &n1);

    // Loop na through First tree ma infos recursive insert karo
    printf("Enter nodes of first tree: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &info);
        root1 = insert(root1, info);
    }

    // Bija tree mate node count scan karo
    printf("Enter number of nodes for second tree: ");
    scanf("%d", &n2);

    // Loop na through Second tree ma infos recursive insert karo
    printf("Enter nodes of second tree: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &info);
        root2 = insert(root2, info);
    }

    // sameTree function call kari result evaluate karo
    if (sameTree(root1, root2))
        printf("Given trees are same");
    else
        printf("Given trees are not same");

    return 0;
}