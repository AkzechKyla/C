/* Write a C program to convert a binary number into a decimal number
without using array, function and while loop. */

#include <stdio.h>

int main() {
    int input_binary;
    int digit = 0;
    int position = 1;
    int decimal = 0;
    int i = 1;

    printf("\nInput a binary number : ");
    scanf("%d", &input_binary);

    int temp = input_binary;
    for (int j = temp; j > 0; j = j/10) {
        digit = j % 10;

        if (i == 1) {
            position = position * 1;
        } else {
            position = position * 2;
        }

        decimal = decimal + (digit * position);
        i++;
    }

    printf("\nThe Binary Number : %d", input_binary);
    printf("\nThe equivalent Decimal Number : %d", decimal);

    return 0;
}
