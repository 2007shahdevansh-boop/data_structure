#include <stdio.h>
#include <string.h>
void main() {
    int n, i, j;
    char names[100][50], temp[50];

    printf("Enter the number of names: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter letters %d: ", i + 1);
        scanf("%s", names[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

   
    for(i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
}