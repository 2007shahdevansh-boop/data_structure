#include <stdio.h>
void main() {
    int n, i, num1, num2, index = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Enter the first number to replace: ");
    scanf("%d", &num1);
    printf("Enter the second number to replace with: ");
    scanf("%d", &num2);

    for(i = 0; i < n; i++) {
        if(numbers[i] == num1) {
            numbers[i] = num2;
            index = i;
            break;
        }
    }
    printf("Final array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
} 