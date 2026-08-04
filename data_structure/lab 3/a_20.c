#include <stdio.h>
void main() {
    int n, i, j, duplicate = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(numbers[i] == numbers[j]) {
                duplicate = 1;
                break;
            }
        }
        if(duplicate) {
            break;
        }
    }

    if(duplicate) {
        printf("The array contains duplicate numbers.\n");
    } else {
        printf("The array does not contain any duplicate numbers.\n");
    }
}