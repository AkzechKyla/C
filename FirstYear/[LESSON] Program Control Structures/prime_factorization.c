/*

Activities/Assessments Lesson 4: Program Control Structure

CASE STUDY 1
Write a program that accepts a positive integer and gives its prime factorization, that 
expresses the integer as a product of primes.

*/

#include <stdio.h>

int main() {
    int input;

    printf("Enter non-negative integer: ");
    scanf("%d", &input);

    int n = input;
    int d = 2;

    printf("Prime factorization: 1");

    while (n > 1) {
        while (n % d == 0) {
            printf(" * %d", d);
            n /= d;
        }

        d += 1;
    }

    printf(" = %d\n", input);
    return 0;
}
