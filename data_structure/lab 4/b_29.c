#include <stdio.h>
void main() {
    int n1, n2, i, j;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);

    int arr1[n1];

    for(i = 0; i < n1; i++) {
        printf("Enter element %d of the first array: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);

    int arr2[n2];

    for(i = 0; i < n2; i++) {
        printf("Enter element %d of the second array: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    int merged[n1 + n2];

    for(i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }

    for(j = 0; j < n2; j++) {
        merged[i + j] = arr2[j];
    }

    printf("Merged array: ");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
}