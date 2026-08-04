#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct arr{
    int first;
    int last;
};

struct arr stack[MAX];
int top = -1;

void push(int first,int last) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top].first = first;
    stack[top].last = last;
}

struct arr pop(){

    if(top==-1){
        printf("invalid paranthesis");
        struct arr dummy = {-1,-1};
        return dummy;
    }

    return stack[top--];

}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("stack: ");
    for (i = 0; i < top; i++) {
        printf("(%d , %d) ->", stack[i].first,stack[i].last);
    }
    printf("(%d , %d)", stack[i].first,stack[i].last);
}

int compare(const void *a, const void *b) {
    struct arr *i1 = (struct arr *)a;
    struct arr *i2 = (struct arr *)b;
    return i1->first - i2->first;
}

void overlap(struct arr x[], int count) {
    if (count <= 0) return;

    qsort(x, count, sizeof(struct arr), compare);

    int i = 0;
    push(x[i].first, x[i].last);
    i++;
    while (i < count) {
        if (stack[top].last >= x[i].first) {
            struct arr temp = pop();
            if (temp.last > x[i].last && temp.first<x[i].first) {
                push(temp.first, temp.last);
            }
            else if(temp.last < x[i].last && temp.first>x[i].first){
                push(x[i].first, x[i].last);
            }
            else{
                push(temp.first, x[i].last);
            }
        }
        else {
            push(x[i].first, x[i].last);
        }
        i++;
    }
}

int main(){
    int a,count=0;
    struct arr x[MAX];

    do{
        printf("Enter interval = ");
        scanf("%d %d",&x[count].first,&x[count].last);
        count++;
        printf("Do you want to add another interval? (1 for Yes, 0 for No): ");
        scanf("%d",&a);
    }while(a==1);
    overlap(x,count);
     
    display();

}