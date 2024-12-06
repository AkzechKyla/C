/*

Activities/Assessments Lesson 6: Function

PROGRAMMING EXERCISES 6-6
Two positive integers i and j are considered to be relatively prime if there exist no integer 
greater than 1 that divides them both. Write a function rel_prime that has two input 
parameters, I and j, and returns a value of 1 if and only if I and j are relatively prime. 
Otherwise, rel_prime should return a value of 0.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int rel_prime(int i, int j) {
    int n;
    // Iterate over all integers from 2 to the minimum of i and j
    for(n = 2; n <= (i < j ? i : j); n++) {
        // Check if n is a common factor of i and j
        if(i % n == 0 && j % n == 0) {
            // If n is a common factor, i and j are not relatively prime
            return 0;
        }
    }
    // If no common factor is found, i and j are relatively prime
    return 1;
}

void rel_prime_calculator() {
    int i, j;
    int is_input_success;

    system("cls");
    printf("\n\tRELATIVELY PRIME NUMBERS CALCULATOR\n");
    printf("\t   (Enter two positive integers)\n");

    do {
        printf("\t\t   = ");
        is_input_success = scanf("%d %d", &i, &j);

        if (is_input_success == 0 || i < 0 || j < 0) {
            printf("\tPlease input two positive integers only.\n");
            while (getchar() != '\n');
        } else {
            is_input_success == 1;
            if(rel_prime(i, j)) {
                printf("\n\t%d and %d are relatively prime.\n", i, j);
                break;
            } else {
                printf("\n\t%d and %d are not relatively prime.\n", i, j);
                break;
            }
        }
    } while (is_input_success == 0 || i < 0 || j < 0);
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
            rel_prime_calculator();
        } else {
            break;
        }
    }
}

int main() {

    rel_prime_calculator();
    start_input_loop();

    return 0;
}
