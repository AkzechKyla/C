/*

Activities/Assessments Lesson 4: Program Control Structure

CASE STUDY 3
Write a program that will input non-negative integer and call a function DWARF to 
determine if the integer is DWARF or NOT. An integer is said to be DWARF if the sum of 
its factors is greater than the half of the number.

Example:
Input number: 6
Factors are: 1 2 3
Sum of its factor: 1 +2 + 3 =6
Half of the number : 6 /2 = 3
6 is DWARF

Input number: 9
Factors are 1,3
Sum of its factors : 1 + 3 = 4
Half of number : 9 / 2 = 4.5
9 is NOT DWARF


*/

#include <stdio.h>
#include <stdbool.h>

bool int_in_array(int value, int *array) {
    for (int i = 0; i < 10; i++) {
        if (array[i] == value) {
            return true;
        }
    }

    return false;
}

void get_factors(int n, int *array) {
    int index = 0;
    int d = 2;

    while (n > 1) {
        while (n % d == 0) {
            if (!int_in_array(d, array)) {
                array[index] = d;
                index++;
            }

            n /= d;
        }

        d += 1;
    }
}

int main() {
    int input;
    int factors[10] = {0};
    int sum = 1;
    int ans;

    do {
        printf("\nPlease input a number: ");
        if (scanf("%d", &input) == 0) {
            printf("Invalid output.\n");
            return 0;
        }

        get_factors(input, factors);

        printf("Factors are: 1 ");
        for (int i = 0; i < 10; i++) {
            if (factors[i] > 0) {
                printf("%d ", factors[i]);
            }
        }

        printf("\nSum of its factors: 1");
        for (int i = 0; i < 10; i++) {
            if (factors[i] > 0) {
                sum += factors[i];
                printf(" + %d", factors[i]);
            }
        }
        printf(" = %d\n", sum);

        double half = (double) input / 2;
        if (input % 2 == 0) {
            printf("Half of number: %d / 2 = %d\n", input, (int) half);
        } else if (input % 2 == 1) {
            printf("Half of number: %d / 2 = %.1f\n", input, half);
        }

        if (sum > half) {
            printf("%d is DWARF", input);
        } else {
            printf("%d is NOT DWARF", input);
        }

        printf("\n\nWould you like to try again?");
        printf("\nPress 1 to continue. Press any key to exit.\n");
        scanf("%d", &ans);
    
    } while (ans == 1);

    printf("\n");
    return 0;
}
