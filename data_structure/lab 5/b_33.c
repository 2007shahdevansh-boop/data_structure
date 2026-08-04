#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sortString(char *str) {
    int n = strlen(str);
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
void main() {
    int n, randomIndex;
    char words[100][50], userInput[50];

    printf("Enter the number of words: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    randomIndex = rand() % n;
    printf("Anagram of the word '%s': ", words[randomIndex]);
    scanf("%s", userInput);

    char sortedOriginal[50], sortedUserInput[50];
    strcpy(sortedOriginal, words[randomIndex]);
    strcpy(sortedUserInput, userInput);

    sortString(sortedOriginal);
    sortString(sortedUserInput);

    if(strcmp(sortedOriginal, sortedUserInput) == 0) {
        printf("Correct! '%s' is an anagram of '%s'.\n", userInput, words[randomIndex]);
    } else {
        printf("Incorrect! '%s' is not an anagram of '%s'.\n", userInput, words[randomIndex]);
    }
}