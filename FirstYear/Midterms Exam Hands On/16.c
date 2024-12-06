/* Write a program in C to convert a decimal number into octal without using an array. */

#include <stdio.h>

int main() {
    int decimalNum, quotient, octalNum = 0, temp, position = 1;

    printf("Enter a number to convert: ");
    scanf("%d", &decimalNum);

    quotient = decimalNum;

    while (quotient != 0) {
        temp = quotient % 8;
        octalNum += temp * position;
        quotient /= 8;
        position *= 10;
    }

    printf("The Octal of %d is %d.\n", decimalNum, octalNum);

    return 0;
}
