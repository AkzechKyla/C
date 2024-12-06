/*

9. Write a program in C to print all perfect numbers in a given range using the function.
Test Data :
Input lowest search limit of perfect numbers : 1
Input lowest search limit of perfect numbers : 100
Expected Output :
 The perfect numbers between 1 to 100 are :
 6   28

*/

#include <stdio.h>

int is_perfect(int number) {
    // "perfect number, a positive integer that is equal to the sum of its proper divisors"
    // tbh, I dont really know what a perfect number is
    // I'll just implement the function based on the definition above

    int sum = 0;  // this will be the sum of the proper divisors

    for (int i = 1; i < number; i++) {
        // If "number" is divisible by "i"
        if (number % i == 0) {
            sum += i;
        }
    }

    if (sum == number) return 1;
    return 0;
}

int main() {
    int lowest;
    int highest;

    printf("Input lowest search limit of perfect numbers : ");
    scanf("%d", &lowest);

    printf("Input highest search limit of perfect numbers : ");
    scanf("%d", &highest);

    printf("The perfect numbers between %d to %d are :\n", lowest, highest);
    for (int i = lowest; i <= highest; i++) {
        if (is_perfect(i)) {
            printf("%d   ", i);
        }
    }

    printf("\n");
    return 0;
}
