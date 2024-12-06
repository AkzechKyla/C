/* Write a program in C to convert a decimal number to a binary number using the function. */

#include <stdio.h>

void converter(int decimal)
{
    if (decimal > 0)
	{
        converter(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main(int argc, const char * argv[])
{
    int decimal;

    printf("Input any decimal number: ");
    scanf("%d", &decimal);

	printf("The binary value is: ");
    converter(decimal);

    return 0;
}
