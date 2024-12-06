/*

Activities/Assessments Lesson 6: Function

CASE STUDY 1
The proper divisor of an integer N are the positive divisors less than N, a positive integer 
is said to be DEFICIENT, PERFECT or ABUNDANT numbers if the sum of its proper 
divisors is less than, equal to or greater than the number respectively. Write a program 
using function call by reference to input integer N and call function KOMPUTE to 
determine of integer N is DEFICIENT, PERFECT or ABUNDANT . 
Example:
Input N : 8 
87
Proper divisors are 1,2 4
Sum of proper divisors: 1 + 2 + 4 = 7
7 < 8 is DEFICIENT 
Input N : 6 
Proper divisors are 1,2 3
Sum of proper divisors: 1 + 2 + 3 = 6
6 < 6 is PERFECT 
Input N : 12 
Proper divisors are 1,2, 3, 4,6
Sum of proper divisors: 1 + 2 + 3 + 4 + 6 = 16
16 > 12 is ABUNDANT

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void show_instructions() {
    system("cls");
    printf("\n\tDIVISORS CALCULATOR\n");
    printf("\nInput a positive integer and this calculator will calculate and determine:\n");
    printf("\t*the list of divisors of the given number\n");
    printf("\t*the sum of its divisors\n");
    printf("\t*if the number DEFICIENT, PERFECT, or ABUNDANT\n\n");
}

void KOMPUTE(int *n) {
    int sum = 1; // Start with 1 since it is always a proper divisor
    int i;
    printf("Proper divisors are 1");
    for(i = 2; i < *n; i++) {
        if(*n % i == 0) {
            printf(", %d", i);
        }
    }
    printf("\nSum of proper divisors: 1");
    for (i = 2; i < *n; i++) {
        if (*n % i == 0) {
            printf(" + %d", i);
            sum += i;
        }
    }
    printf(" = %d\n", sum);
    if(sum < *n) {
        printf("%d < %d is DEFICIENT\n", sum, *n);
    } else if(sum == *n) {
        printf("%d = %d is PERFECT\n", sum, *n);
    } else {
        printf("%d > %d is ABUNDANT\n", sum, *n);
    }
}

int get_user_input() {
    int n;

    while (1) {
        printf("Input N: ");
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Invalid input. Please enter no less than 0 integers only.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }

    return n;
}

void start_input_loop() {
    // This function loops the program
    int choice = 0;
    int n;

    while (true) {

        printf("\n\nWould you like to try the program again?\n");
        printf("Press 1 to continue. Press any key to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n");
            show_instructions();
            n = get_user_input();
            KOMPUTE(&n);
        } else {
            break;
        }
    }
}

int main() {
    show_instructions();

    int n = get_user_input();

    KOMPUTE(&n);
    start_input_loop();

    return 0;
}
