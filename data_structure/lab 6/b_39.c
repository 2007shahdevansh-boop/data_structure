#include <stdio.h>
#include <string.h>
void main() {
    char str[100];
    char *ptr_start, *ptr_end;
    int is_palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = 0;

    ptr_start = str; 
    ptr_end = str + strlen(str) - 1; 

    while(ptr_start < ptr_end) {
        if(*ptr_start != *ptr_end) {
            is_palindrome = 0; 
            break;
        }
        ptr_start++;
        ptr_end--;
    }

    if(is_palindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
}