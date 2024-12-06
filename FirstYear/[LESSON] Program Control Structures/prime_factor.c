/*

Activities/Assessments Lesson 4: Program Control Structure

Write a program that will input non-negative integer and would display the prime factors 
of the given integer.
Example:
Enter non-negative number: 15
62
Prime factors are: 1 3 5

*/

#include <stdio.h>

int main()
{
    int n;
    int d = 2;
    int ans;

    do {
        printf("\n\tPrime Factor Calculator\n\n");
        printf("Enter non-negative integer: ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        if (n < 0) {
            printf("Enter non-negative integer only.");
            return 0;
        }

        printf("Prime factors are: 1 ");
        while (n > 1) {
            while (n % d == 0) {
                printf("%d ", d);
                n /= d;
            }

            d += 1;
        }

        printf("\n\nWould you like to try again?");
        printf("\nPress 1 to continue. Press any key to exit.\n");
        scanf("%d", &ans);
    } while (ans == 1);

    return 0;
}
