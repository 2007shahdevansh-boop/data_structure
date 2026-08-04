struct node{
    int exponent;
    int coefficient;
    struct node* next;
};

struct node* pol1=NULL;
struct node* pol2=NULL;
struct node* sumPol=NULL;

void insert(int a,int exp,int coeff){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->exponent=exp;
    newnode->coefficient=coeff;
    if(a==1){
        
        struct node* curr=pol1;
        if(curr==NULL){
        
        newnode->next=NULL;
        curr=newnode;
        pol1=curr;
        }
        else{
            while(curr->next != NULL){
            curr=curr->next;
        }

        newnode->next=NULL;
        curr->next=newnode;
        }
        
    }

    if(a==2){
        struct node* curr=pol2;
        if(curr==NULL){
        
        newnode->next=NULL;
        curr=newnode;
        pol2=curr;
        }
        else{
            while(curr->next != NULL){
            curr=curr->next;
        }

        newnode->next=NULL;
        curr->next=newnode;
        }
    }

    if(a==3){
        struct node* curr=sumPol;
        if(curr==NULL){
        
        newnode->next=NULL;
        curr=newnode;
        sumPol=curr;
        }
        else{
            while(curr->next != NULL){
            curr=curr->next;
        }

        newnode->next=NULL;
        curr->next=newnode;
        }
    }
}

void sum() {
    struct node* p1 = pol1;
    struct node* p2 = pol2;
    struct node* resultHead = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent > p2->exponent) {
            insert(3, p1->exponent, p1->coefficient);
            p1 = p1->next;
        } 
        else if (p1->exponent < p2->exponent) {
            insert(3, p2->exponent, p2->coefficient);
            p2 = p2->next;
        } 
        else {
            int sumCoeff = p1->coefficient + p2->coefficient;
            insert(3, p1->exponent, sumCoeff);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(3, p1->exponent, p1->coefficient);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(3, p2->exponent, p2->coefficient);
        p2 = p2->next;
    }

}

void display(int a){
    if(a==1){
        struct node* dis=pol1;
        while(dis->next!=NULL){
            if(dis->coefficient==0){
                
            }
            else if(dis->exponent==0){
                printf("%d + ",dis->coefficient);
            }
            else{
                printf("%dX^%d + ",dis->coefficient,dis->exponent);
            }
            dis=dis->next;
        }

            if(dis->coefficient==0){

            }
            else if(dis->exponent==0){
                printf("%d",dis->coefficient);
            }
            else{
                printf("%dX^%d",dis->coefficient,dis->exponent);
            }

    }

    if(a==2){
        struct node* dis=pol2;
        while(dis->next!=NULL){
            if(dis->coefficient==0){
                
            }
            else if(dis->exponent==0){
                printf("%d + ",dis->coefficient);
            }
            else{
                printf("%dX^%d + ",dis->coefficient,dis->exponent);
            }
            dis=dis->next;
        }

        if(dis->coefficient==0){
                    
            }
            else if(dis->exponent==0){
                printf("%d",dis->coefficient);
            }
            else{
                printf("%dX^%d",dis->coefficient,dis->exponent);
            }
    }

    if(a==3){
        struct node* dis=sumPol;
        while(dis->next!=NULL){
            if(dis->coefficient==0){
                
            }
            else if(dis->exponent==0){
                printf("%d + ",dis->coefficient);
            }
            else{
                printf("%dX^%d + ",dis->coefficient,dis->exponent);
            }
            dis=dis->next;
        }
        if(dis->coefficient==0){
                    
            }
            else if(dis->exponent==0){
                printf("%d",dis->coefficient);
            }
            else{
                printf("%dX^%d",dis->coefficient,dis->exponent);
            }
    }
}
void main(){
    int exp,coeff,choice;

        printf("enter for first polynomial:");

    do
    {
        printf("Enter exponent = ");
        scanf("%d", &exp);
        printf("Enter coefficient = ");
        scanf("%d", &coeff);
        insert(1,exp,coeff);
        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);
    printf("Data in first polynomial: ");
    display(1);

    printf("enter for second polynomial:");

    do
    {
        printf("Enter exponent = ");
        scanf("%d", &exp);
        printf("Enter coefficient = ");
        scanf("%d", &coeff);
        insert(2,exp,coeff);
        printf("Do you want to add another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);
    printf("Data in second polynomial: ");
    display(2);

    sum();

    printf("answer of polynomial1 + polynomial2 is :");

    display(3);

}