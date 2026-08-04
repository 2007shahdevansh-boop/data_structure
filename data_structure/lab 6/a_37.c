#include <stdio.h>
void main() {
    int n, i, largest;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr; 

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

    largest = *ptr; 

    for(i = 1; i < n; i++) {
        if(*(ptr + i) > largest) {
            largest = *(ptr + i);
        }
    }

    printf("The largest element in the array is: %d\n", largest);
}