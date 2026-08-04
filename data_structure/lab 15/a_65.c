#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 400
char stack[MAX];
int top=-1;
char postfix[MAX];

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

int precedence(char p){
    if(p=='^'){
        return 3;
    }
    if(p=='*' || p=='/'){
        return 2;
    }
    if(p=='+' || p=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void infix_to_postfix(char PE[MAX]){
    int i=-1;

    for(int j=0;j<strlen(PE);j++){
        if(PE[j]=='+' || PE[j]=='-' || PE[j]=='*' || PE[j]=='/' || PE[j]=='^'){
            if(top==-1){
                push(PE[j]);
            }
            else if(precedence(PE[j])>precedence(stack[top])){
                push(PE[j]);
            }
            else if(precedence(PE[j])<=precedence(stack[top])){
               while(top != -1 && stack[top] != '(' && precedence(PE[j]) <= precedence(stack[top])){
                    postfix[++i]=pop();
                }
                push(PE[j]);
            }
        }
        else if(PE[j]==')'){
            while(stack[top]!='('){
                postfix[++i]=pop();
            }
            pop();
        }
        else if(PE[j]=='('){
            push(PE[j]);
        }
        else{
            postfix[++i]=PE[j];
        }
    }

    while(top!=-1){
        postfix[++i]=pop();
    }

    postfix[++i] = '\0';
}

int main(){
    char PE[MAX];

    printf("enter the given expression:");
    gets(PE);

    infix_to_postfix(PE);

    printf("postfix expression is:\n");
    puts(postfix);

    return 0;
}