#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
char stack[MAX];
int top=-1;

void push(char value){
    if(top==MAX-1){
        printf("stack overflow....");
        return;
    }
    stack[++top]=value;
}

char pop(){

    if(top==-1){
        printf("stack is empty....");
        return -1;
    }

    return stack[top--];
}

void compare(char a[]){
    int c = 0;
    for(int i=0;i<strlen(a);i++){
        
        char ch = a[i];
        if(c == 0 && (ch=='a'||ch=='b')){
            push(ch);
        }
        else if(ch == 'c'){
            if(c == 1){
                printf("invalid");
                return;
            }
            c = 1;
        }
        else if((ch == 'a' || ch== 'b')&& c==1){
            if(top == -1){
            printf("invalid");
            return;
        }
            int temp = pop();
            if(temp != ch){
                printf("invalid");
                return;
            }
        }
    }
    if(c == 1 && top == -1) {
        printf("valid");
    } else {
        printf("invalid");
    }
}

void main(){
    char a[100];
    printf("enter the given string:");
    gets(a);

    compare(a);
}