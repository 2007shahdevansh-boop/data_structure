#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char value){
    if(top == MAX -1){
        printf("stack overflow");
        return;
    }
    stack[++top] = value;
}

char pop(){
    if(top==-1){
        printf("stack is empty");
        return -1;
    }
    return stack[top--];
}

void display(){
    for(int i=0;i<=top;i++){
        printf("%c",stack[i]);
    }
}

void swap(char a[],int n){
    top = -1;
    for(int i=0;i<n;i++){
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U'){
            char temp[100];
            int count =0;

            while (top >= 0) {
                temp[count++] = pop();
            }

            for (int j = 0; j < count; j++) {
                push(temp[j]);
            } 
            push(a[i]);
        }
        else{
            push(a[i]);
        }
    }
}

int main(){
    char a[100];
    int c=1;

    do{
        printf("enter the given string:");
        gets(a);

        swap(a,strlen(a));

        printf("swapped string:\n");
        display();

        printf("\nDo you want to enter another string? (1 for Yes, 0 for No): ");
        scanf("%d", &c);
    }while(c==1);

    return 0;
}