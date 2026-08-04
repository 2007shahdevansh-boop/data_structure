#include <stdio.h>
void main() {
    int m, n, sum = 0;
    printf("Enter the value of m: ");
    scanf("%d", &m);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int arr[n - m + 1];
    
    for (int i = 0; i <= n - m; i++) {
        arr[i] = m + i;
        sum += arr[i];
    }
    
    printf("The sum of numbers from %d to %d is: %d\n", m, n, sum);
}