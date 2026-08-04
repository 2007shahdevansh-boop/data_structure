#include <stdio.h>
void main() {
    int n, i, smallest, largest, pos_smallest, pos_largest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    smallest = numbers[0];
    largest = numbers[0];
    pos_smallest  = 0;
    pos_largest = 0;

    for(i = 1; i < n; i++) {
        if(numbers[i] < smallest) {
            smallest = numbers[i];
            pos_smallest = i;
        }
        if(numbers[i] > largest) {
            largest = numbers[i];
            pos_largest = i;
        }
    }

    printf("The smallest number is %d at position %d\n", smallest, pos_smallest + 1);
    printf("The largest number is %d at position %d\n", largest, pos_largest + 1);
} 