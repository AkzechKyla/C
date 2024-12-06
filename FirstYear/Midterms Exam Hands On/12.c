/*

12. Write a program in C to make a pyramid pattern with numbers increased
  by 1.
   1
  2 3
 4 5 6
7 8 9 10

*/

#include <stdio.h>

int main() {
    // Again, this is literally the same thing as number 11,
    // but with extra padding on the left to make it look like a pyramid
    // So Ill just copy paste the code again from number 11

    int size = 4;
    int counter = 1;

    for (int i = 0; i < size; i++) {
        // We need to print a padding for every outer iteration
        // To calculate the padding size, we will use this formula:
        int paddingSize = size / 2 - i + 1;

        // As for the explantion for the formula...
        // Welp I just figured it out through trial and error until I get the pyramid shape

        // Then lets print the padding
        for (int p = 0; p < paddingSize; p++) {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++) {
            printf("%d ", counter);
            counter++;
        }

        printf("\n");
    }

    return 0;
}
