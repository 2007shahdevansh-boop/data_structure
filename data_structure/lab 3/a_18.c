#include <stdio.h>
void main() {
    
    int n, i;
    float sum = 0.0, average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n]; 

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];}

    average = sum / n;

    printf("Average of first %d numbers is: %.2f\n", n, average);
}