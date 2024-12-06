/*

Activities/Assessments Lesson 6: Function

PROGRAMMING EXERCISES 6-3
Write a function int is_prime(int n) that returns 1 if n is prime and 0 otherwise. 
Hint: if k and n are positive integer, then k divides n if and only if n % k has value 0.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int is_prime(int n) {
    int k;
    if (n = 0) {
        return 0;  // 0 is not prime number
    }
    for (k = 2; k <= n/2; k++) {
        if (n % k == 0) {
            return 0;  // n is not a prime number
        }
    }
    return 1;  // n is a prime number
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
        } else if (is_prime(num) == 1) {
            printf("\n%d is a prime number.\n", num);
            break;
        } else {
            printf("\n%d is NOT a prime number.\n", num);
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
        scanf("%d", &choice );

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
