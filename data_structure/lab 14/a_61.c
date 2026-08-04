#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char value) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

char pop(){

    if(top==-1){
        printf("invalid paranthesis");
        return -1;
    }

    return stack[top--];
}

bool is_matching(char a,char b){
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    return false;
}

void check(char a[]){
    top = -1;
    int i;
    for(i=0;i<strlen(a);i++){
        int ch = a[i];
        if(ch == '(' || a[i] == '[' || a[i] == '{'){
            push(ch);
        }
        else if(ch == ')' || a[i] == ']' || a[i] == '}'){
            if(top == -1){
                printf("invalid paranthesis.");
                return;
            }
            int x=pop();
            if(!is_matching(x,ch)){
                printf("invalid paranthesis.");
                return;
            }
        }
        else{
            printf("invalid string");
            return;
        }
    }
    if(top != -1){
        printf("invaid parantheis");
    }
    else
    {printf("valid");}
}

void main(){
    char a[100];
    printf("enter the given string:");
    gets(a);

    check(a);
}