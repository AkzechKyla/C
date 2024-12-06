/*

13. Write a program in C to print Floyd's Triangle.
1
01
101
0101
10101

*/

#include <stdio.h>

int main() {
    // This is same as number 10 again
    // you know the drill
    // its copy and paste the code again time

    int size = 5;  // this time, the size is 5
    int value = 1;  // number to print

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d", value);

            // invert the number
            if (value == 0) value = 1;
            else if (value == 1) value = 0;
        }

        // In the outer loop, if the index (i) is odd,
        // we need to invert the number again
        // Because the "value" needs to alternate in both x and y axis (or rows and columns)
        if (i % 2 == 1) {
            if (value == 0) value = 1;
            else if (value == 1) value = 0;
        }

        printf("\n");
    }

    return 0;
}
