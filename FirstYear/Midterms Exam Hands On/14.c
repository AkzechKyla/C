/*

14. Write a program in C to find the number and sum of all integers between
100 and 200 which are divisible by 9.

Expected Output:
Numbers between 100 and 200, divisible by 9:
108 117 126 135 144 153 162 171 180 189 198
The sum: 1683

*/

#include <stdio.h>

int main() {
    int sum = 0;  // sum of all divisibles

    printf("Numbers between 100 and 200, divisible by 9:\n");

    // Loop for 100-200 (both ends inclusive I assume)
    for (int i = 100; i <= 200; i++) {
        // If you divide the `i` by 9, and the remainder is 0,
        // that means `i` is divisible by 9
        if (i % 9 == 0) {
            printf("%d ", i);
            sum += i;
        }
    }

    printf("\nThe sum: %d\n", sum);
    return 0;
}
