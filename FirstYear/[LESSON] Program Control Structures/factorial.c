/*

Activities/Assessments Lesson 4: Program Control Structure

CASE STUDY 2
N factorial can be defined as the product of all integers from 1 to N and it is denoted by 
the symbol N!. 0! (zero factorial) is defined as 1. Write a program that will input N and 
would display N factorial. (Determine first if N is a nonnegative integer).

*/

#include <stdio.h>

long factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main() {
    int input;
    
    printf("\n\t Positive Integer Factorial Calculator\n\n");
    printf("Enter non-negative integer: ");
    scanf("%d", &input);

    if (input < 0) {
        printf("N must be a positive integer.\n");
        return 0;
    }

    printf("\nFactorial of %d is %lu.\n", input, factorial(input));
    return 0;
}
