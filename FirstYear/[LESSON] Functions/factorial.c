/*

Activities/Assessments Lesson 6: Function

PROGRAMMING EXERCISES 6-1
N factorial can be define as the product of all integer from 1 to N and it is denoted by the 
symbol N!.0! (zero factorial) is defined a 1. Write a program that will input N and would 
call the function factorial that will return N factorial. (Determine first if N is a nonnegative 
integer).

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long factorial(int n) {
    if (n == 0) {
        return 1;
    }
        return n * factorial(n - 1);
}

void factorial_calculator() {
    int n;
    long result;

    system("cls");
    printf("\n\tFactorials Calculator\n");
    printf("\t\tn! = ?\n");

    while (1) {
        printf("\n    (Enter a non-negative integer)\n");
        printf("\t\tn = ");
        if (scanf("%d", &n) != 1 || n < 0) {
            printf("\n\tInvalid input. Please try again.\n");
            while (getchar() != '\n');
        } else if (n < 0) {
            printf("n must be > or = to 0\n");
        } else {
            result = factorial(n);
            printf("\n\t\t%d! = %lu\n", n, result);
            break;
        }
    }
}

void start_input_loop() {
    // This function loops the program

    while (true) {
        int choice = 0;

        printf("\n\nWould you like to try the program again?\n");
        printf("Press 1 to continue. Press any key to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n");
            factorial_calculator();
        } else {
            break;
        }
    }
}

int main() {

    factorial_calculator();
    start_input_loop();

    return 0;
}
