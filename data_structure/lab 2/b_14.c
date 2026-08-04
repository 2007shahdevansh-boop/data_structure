#include <stdio.h>
void main()
{
    int n, sum = 0, total_sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        sum += i;
        
        total_sum += sum;
        
    }
    
    printf("The total sum is: %d\n", total_sum);
}
