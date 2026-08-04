#include <stdio.h>
struct Student {
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};
void main() {
    struct Student student;
    struct Student *ptr = &student;

    printf("Enter roll number: ");
    scanf("%d", &ptr->roll_no);
    printf("Enter name: ");
    scanf("%s", ptr->name);
    printf("Enter branch: ");
    scanf("%s", ptr->branch);
    printf("Enter batch number: ");
    scanf("%d", &ptr->batch_no);

    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Branch: %s\n", ptr->branch);
    printf("Batch Number: %d\n", ptr->batch_no);
}