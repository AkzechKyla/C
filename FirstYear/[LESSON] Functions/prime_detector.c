/*

Activities/Assessments Lesson 6: Function

PROGRAMMING EXERCISES 6-2
An integer is considered prime if its only factors are 1 and itself. 1 can be considered a 
prime integer because its factors are 1 and only 1. Write a program that will input a 
nonnegative and would call the function prime that returns 0 for true and 1 for false. 
(Precondition: Test if the entered value is nonnegative)

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int prime(int n) {
    int i;
    if (n = 0) {
        return 1;  // 0 is not prime number
    }
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 1;  // n is not a prime number
        }
    }
    return 0;  // n is a prime number
}

void prime_numbers_calculator() {
    int num;

    system("cls");
    printf("\n\tPrime Numbers Calculator\n");
    printf("    Is this Number Prime or Composite?\n\n");

    while (1) {
        printf("\n      (Enter a non-negative integer)\n");
        printf("\t\t = ");
        if (scanf("%d", &num) != 1 || num < 0) {
            printf("\n\tInvalid input. Please try again.\n");
            while (getchar() != '\n');
        } else if (num <= 0) {
            printf("\nInvalid input: Please enter only positive non-zero integers.\n");
            while (getchar() != '\n');
        } else if (prime(num) == 0) {
            printf("\n%d is a prime number.\n", num);
            break;
        } else {
            printf("\n%d is not a prime number.\n", num);
            printf("It is a composite number and can be factored \nby any positive numbers other than 1 and itself.\n");
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
            prime_numbers_calculator();
        } else {
            break;
        }
    }
}

int main() {

    prime_numbers_calculator();
    start_input_loop();

    return 0;
}
