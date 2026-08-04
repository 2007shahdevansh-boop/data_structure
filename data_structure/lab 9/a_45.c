 #include<stdio.h>
 #include<stdlib.h>
 struct node{
     int info;
     struct node *link;
 };
 struct node *first=NULL;
 struct node *copy=NULL;
 void insert (int value){
     struct node *newnode = (struct node *)malloc(sizeof(struct node));
     newnode->info=value;
     newnode->link=first;
     first=newnode;
 }
 void copy_func(){
     struct node* new = (struct node *)malloc(sizeof(struct node));
     while(first!=NULL){
         if(copy==NULL){
             copy->info=first->info;
             copy->link=NULL;
        
         }else{
             while(copy->link!=NULL){
                 copy=copy->link;
             }
             new->info=first->info;
             new->link=NULL;
             copy->link=new;
             first=first->link;
         }
     }
 }
 void display(){
     while(copy->link!=NULL){
         printf("%d -> ",copy->info);
         copy=copy->link;
     }
     printf("NULL");
 }
 void main(){
     int value;
     do{
         printf("Enter info = ");
         scanf("%d",&value);
         insert(value);
         printf("Do you want to add another node? (1 for Yes, 0 for No): ");
         scanf("%d",&value);
     }while(value==1);
     copy_func();
     printf("hello");
     display();
 }