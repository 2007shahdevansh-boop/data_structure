#include <stdio.h>
void main() {
    int n, i, num, pos = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n]; 

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Enter the number to delete: ");
    scanf("%d", &num);

    for(i = 0; i < n; i++) {
        if(numbers[i] == num) {
            pos = i;
            break;
        }
    }

    if(pos != -1) {
        for(i = pos; i < n - 1; i++) {
            numbers[i] = numbers[i + 1];
        }
        printf("Final array: ");
        for(i = 0; i < n - 1; i++) {
            printf("%d ", numbers[i]);
        }
    } else {
        printf("Number not found in the array.\n");
    }
}