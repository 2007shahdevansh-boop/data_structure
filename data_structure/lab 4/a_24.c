#include <stdio.h>
void main() {
    int n, i, num, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n + 1]; 

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    for(i = n; i >= pos; i--) {
        numbers[i] = numbers[i - 1];
    }
    
    numbers[pos - 1] = num;

    printf("Final array: ");
    for(i = 0; i <= n; i++) {
        printf("%d ", numbers[i]);
    }
}