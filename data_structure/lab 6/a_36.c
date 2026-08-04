#include <stdio.h>
void main() {
    int n, i, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];
    int *ptr = numbers; 

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i); 
    }

    printf("The sum of the entered numbers is: %d\n", sum);
}