#include <stdio.h>
void main() {
    int n, i, j, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; ) {
            if(numbers[i] == numbers[j]) {
                for(k = j; k < n - 1; k++) {
                    numbers[k] = numbers[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }

    printf("Final array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
}