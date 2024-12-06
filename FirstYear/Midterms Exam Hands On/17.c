/* Write a C program to convert an octal number to a decimal without using an array. */

#include <stdio.h>

int main() {
    int octal, decimal = 0, base = 1;

    printf("Input an octal number (using digits 0 - 7): ");
    scanf("%d", &octal);

    int temp = octal;
    while (temp > 0) {
        int digit = temp % 10;
        decimal += digit * base;
        base *= 8;
        temp /= 10;
    }

    printf("The Octal Number: %d\n", octal);
    printf("The equivalent Decimal Number: %d\n", decimal);

    return 0;
}
