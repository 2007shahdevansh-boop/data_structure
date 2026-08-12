#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* right;
    struct node* left;
};

struct node* minValue(struct node* save){
    struct node* current = save;
    while(current->left != NULL || current != NULL){
        current = current->left;
    }

    return current;
}

struct node* search(struct node* save,int key){
    if(save == NULL || save->info == key){
        return save;
    }

    if(key < save->info){
        return search(save->left,key);
    }

    else if(key > save->info){
        return search(save->right,key);
    }
}

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


struct node* delete(struct node* save, int key){
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    if(key < save->info){
        save->left = delete(save->left,key);
        return save;
    }

    else if(key > save->info){
        save->right = delete(save->right,key);
        return save;
    }

    else{

        if(save->left==NULL){
            temp=save->right;
            free(save);
            return temp;
        }

        if(save->right==NULL){
            temp=save->left;
            free(save);
            return temp;
        }

        temp = minValue(save->right);

        save->info = temp->info;

        save->right = delete(save->right,temp->info);
    }
    
    return save;
}

void inOrder(struct node* save){
    if(save == NULL){
        return;
    }

    if(save->left != NULL){
        inOrder(save->left);
    }

    printf("%d",save->info);

    if(save->right != NULL){
        inOrder(save->right);
    }
}

void preOrder(struct node* save){
    if(save == NULL){
        return;
    }

    printf("%d",save->info);

    if(save->left != NULL){
        preOrder(save->left);
    }

    if(save->right != NULL){
        preOrder(save->right);
    }
}

void postOrder(struct node* save){
    if(save == NULL){
        return;
    }

    if(save->left != NULL){
        postOrder(save->left);
    }

    if(save->right != NULL){
        postOrder(save->right);
    }

    printf("%d",save->info);
}

int main()
{
    struct node *root = NULL; // Initial state ma tree ne empty set karo
    struct node *result;

    int choice;
    int info;

    do
    {
        printf("\n\n========== BINARY SEARCH TREE ==========\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter info to insert: ");
                scanf("%d", &info);

                // Insert function call
                root = insert(root, info);

                printf("Node inserted successfully.\n");

                break;


            case 2:

                printf("Enter info to delete: ");
                scanf("%d", &info);

                
                    // Delete karta pehla info exist kare chhe ke nai ae search karo,
                    // jethi user ne proper confirmation message aapi shakaye.
                
                result = search(root, info);

                if (result == NULL)
                {
                    printf("Node not found.\n");
                }
                else
                {
                    root = delete(root, info);
                    printf("Node deleted successfully.\n");
                }

                break;


            case 3:

                printf("Enter info to search: ");
                scanf("%d", &info);

                result = search(root, info);

                if (result == NULL)
                    printf("Node not found.\n");
                else
                    printf("Node found: %d\n", result->info);

                break;


            case 4:

                if (root == NULL)
                {
                    printf("Empty Tree\n");
                }
                else
                {
                    printf("Preorder Traversal: ");
                    preOrder(root);
                    printf("\n");
                }

                break;


            case 5:

                if (root == NULL)
                {
                    printf("Empty Tree\n");
                }
                else
                {
                    printf("Postorder Traversal: ");
                    postOrder(root);
                    printf("\n");
                }

                break;


            case 6:

                if (root == NULL)
                {
                    printf("Empty Tree\n");
                }
                else
                {
                    printf("Inorder Traversal: ");
                    inOrder(root);
                    printf("\n");
                }

                break;


            case 7:

                printf("Program terminated.\n");

                break;


            default:

                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);


    return 0;
}

    