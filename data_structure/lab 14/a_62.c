#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Resulting string: ");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

void remove_string(char a[]){
    top = -1;
    int i;

    for(i=0;i<strlen(a);i++){
        int ch = a[i];
        if(ch == '*'){
            pop();
        }
        else{
            push(ch);
        }
    }
}

int main(){
    char a[100];
    printf("enter the given string:");
    gets(a);

    remove_string(a);
    display();
    return 0;
}