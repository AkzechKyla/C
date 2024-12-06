/*

Activities/Assessments Lesson 4: Program Control Structure

Assume a range of integer values starting from N1 and ending at N2. Assume also an 
integer say M. Write a program that will print and display all the numbers from N1 to N2 
which are divisible by M. You are also required display the count of such numbers. For 
example, if N1 = 4, N2 = 12 and M = 4, the output will be: 4, 8, 12. The value 3 will also be 
displayed indicating that there are 3 numbers which are divisible by 4.

*/

#include <stdio.h>

    int main() {
        int n1, n2, m, ans;
        int divisible_count = 0;

    do {
        printf("--------------------------------------------------");
        printf("\n\tDivisible Numbers Calculator\n\n");
        printf("Give a range of two numbers from (N1) to (N2)\n");

        printf("\n\tN1: ");
        scanf("%d", &n1);

        printf("\tN2: ");
        scanf("%d", &n2);

        printf("\tM: ");
        scanf("%d", &m);

        printf("\nThe following numbers are divisible by %d:\n", m);
        for (int n = n1; n <= n2; n++) {
            if (n % m == 0) {
                divisible_count++;
                printf("%d ", n);
            }
        }
        printf("\n\nThere are %d numbers divisible by %d.\n", divisible_count, m);
        
        printf("\n\nWould you like to try again?");
        printf("\nPress 1 to continue. Press any key to exit.\n");
        scanf("%d", &ans);

    } while (ans == 1);

    return 0;
}
