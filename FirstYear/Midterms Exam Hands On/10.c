/*

Write a program in C to make such a pattern like a right angle triangle with a
number which will repeat a number in a row.

The pattern like:
 1
 22
 333
 4444

*/

#include <stdio.h>

int main() {
    // We can make the pattern with a simple nested loop
    int size = 4;  // good practice to define variable in this case

    // We will iterate 4 times in the outer loop
    for (int i = 0; i < size; i++) {

        // For the inner loop,
        // we iterate incrementally based on the outer loop
        for (int j = 0; j < i + 1; j++) {
            printf("%d", i + 1);
        }

        // Line break for each outer iteration
        printf("\n");
    }

    return 0;
}
