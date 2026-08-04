#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 400
char stack[MAX];
int top=-1;

char prefix[MAX];

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

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
                while (top != -1 && stack[top] != '(' && precedence(stack[top]) > precedence(PE[j])){
                    prefix[++i]=pop();
                }
                push(PE[j]);
            }
        }
        else if(PE[j]==')'){
            while(stack[top]!='('){
                prefix[++i]=pop();
            }
            pop();
        }
        else if(PE[j]=='('){
            push(PE[j]);
        }
        else{
            prefix[++i]=PE[j];
        }
    }

    

    while(top!=-1){
        prefix[++i]=pop();
    }

    prefix[++i] = '\0';

}

void infix_to_prefix(char PE[MAX]){
    char PE1[MAX];
    int i;
    for(i=0; i<strlen(PE); i++){
        if(PE[i]=='('){
            push(')');
        }
        else if(PE[i]==')'){
            push('(');
        }
        else{
            push(PE[i]);
            
        }
    }

    i=-1;
    
    while(top!=-1){
        PE1[++i]=pop();
    }

    PE1[++i] = '\0';

    

    infix_to_postfix(PE1);  

    reverse(prefix);
}


void main(){
    char PE[MAX];
    printf("enter the given expression:");
    gets(PE);

    infix_to_prefix(PE);

    printf("prefix expression is:\n");
    puts(prefix);
}