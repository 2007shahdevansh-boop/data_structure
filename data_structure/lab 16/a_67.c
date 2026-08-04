#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 400
int stack[MAX];
int top=-1;


int solve(int op1,int op2,char x){
    switch (x){
        case '+':
         return (op1 + op2);  
        case '*':
         return (op1 * op2);  
        case '-':
         return (op1 - op2); 
        case '/':
         return (op1 / op2);  
        case '^':
         return (op1 ^ op2);  
        default:
            printf("invalid operator");
            return -1;
    }
}

int convert(char c){

    return c-'0';
}

void push(int value){
    if(top == MAX -1){
        printf("stack overflow");
        return;
    }
    stack[++top] = value;
}

int pop(){
    if(top==-1){
        printf("stack is empty");
        return -1;
    }
    return stack[top--];
}

int evaluation(char a[]){
    int i;
    for(i=0;i<strlen(a);i++){
        if(a[i]=='+'||a[i]=='/'||a[i]=='*'||a[i]=='-'){
            int op2=pop();
            int op1=pop();
            push(solve(op1,op2,a[i]));
        }
        else{
            push(convert(a[i]));
        }
    }
    if(top != 0){
        printf("invalid structure......");
    }

    return stack[top];
}

void main(){
    char PE[MAX];
    printf("enter the given expression:");
    gets(PE);

    int ans = evaluation(PE);
    printf("the answer of the postfix expression is %d",ans);
}