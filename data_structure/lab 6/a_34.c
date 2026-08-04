#include <stdio.h>
#include <stdlib.h>
void main() {
    int *intPtr;
    char *charPtr;
    float *floatPtr;

    intPtr = (int *)malloc(sizeof(int));
    charPtr = (char *)malloc(sizeof(char));
    floatPtr = (float *)malloc(sizeof(float));

    if(intPtr == NULL || charPtr == NULL || floatPtr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter an integer: ");
    scanf("%d", intPtr);
    printf("Enter a character: ");
    scanf(" %c", charPtr);
    printf("Enter a float: ");
    scanf("%f", floatPtr);

    printf("You entered:\n");
    printf("Integer: %d\n", *intPtr);
    printf("Character: %c\n", *charPtr);
    printf("Float: %.2f\n", *floatPtr);

    free(intPtr);
    free(charPtr);
    free(floatPtr);
}