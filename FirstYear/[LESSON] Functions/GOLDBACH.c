/*

Activities/Assessments Lesson 6: Function

PROGRAMMING EXERCISES 6-4
A famous conjecture, called the GOLDBACH conjecture, says that every even integer n 
greater than 2 has the property tat it is the sum of two prime numbers. Computers have 
been used extensively to test this conjecture. No counter example has been found. Write 
a program the will prove that the conjecture is true for all the even integers between the 
symbolic constants START and FINISH. For example, if you write:
#define START 700
#define FINISH 1100
Then the output of your program might look like this:
Every even number greater than 2 is the sum of two primes:
700 = 17 + 683
702 = 11 + 691
704 = 3 + 701
:
:
1098 = 5 + 1093
1100 = 3 + 1097

*/

#include <stdio.h>
#include <stdlib.h>

#define START 700
#define FINISH 1100

int is_prime(int n) {
    int i;
    if (n <= 1) {
        return 0;  // 0 and 1 are not prime numbers
    }
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;  // n is not a prime number
        }
    }
    return 1;  // n is a prime number
}

int main() {
    int i, j;

    system("cls");
    printf("\nEvery even number greater than 2 is the sum of two primes:\n\n");
    for (i = START; i <= FINISH; i += 2) {
        for (j = 2; j <= i/2; j++) {
            if (is_prime(j) && is_prime(i-j)) {
                printf("%d = %d + %d\n", i, j, i-j);
                break;  // found a pair of primes that sum up to i, move to the next even number
            }
        }
    }
    return 0;
}
