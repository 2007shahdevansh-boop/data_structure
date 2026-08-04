//. Write a program to delete a number from a given location in an array. 
#include <stdio.h>
void main() {
    int n, i, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n]; 

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);


    for(i = pos - 1; i < n - 1; i++) {
        numbers[i] = numbers[i + 1];
    }

    printf("Final array: ");
    for(i = 0; i < n - 1; i++) {
        printf("%d ", numbers[i]);
    }
}