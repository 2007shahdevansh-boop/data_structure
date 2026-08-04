#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
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

void compare(char a[]) {
    int c = 0;

    for (int i = 0; i < strlen(a); i++) {
        char ch = a[i];


        if (c == 0 && ch == 'a') {
            push(ch);
        }
        else if (ch == 'b') {
            c = 1; 

            if (top == -1) { 
                printf("invalid");
                return;
            }
            pop(); 
        }
        else {
            printf("invalid");
            return;
        }
    }

    if (c == 1 && top == -1) {
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