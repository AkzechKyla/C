/*

11. Write a program in C to make such a pattern like a right angle triangle
with the number increased by 1.
The pattern like:
   1
   2 3
   4 5 6
   7 8 9 10

*/

#include <stdio.h>

int main() {
    // This is similar to number 10 but the numbers printed are incrementing by 1
    // I'll just copy paste the code from number 10

    int size = 4;
    int counter = 1;  // counter starts at 1 in the pattern

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            // Instead of printing the index of the outer loop: printf("%d", i + 1);
            // We print the "counter" instead
            printf("%d ", counter);
            counter++;
        }

        printf("\n");
    }

    return 0;
}
