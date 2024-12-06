/*

25.Write a C program to get the indices of two numbers in a given array of integers.
This will enable you to get the sum of two numbers equal to a specific target.
Expected Output:
Original Array: 4  2  1  5
Target Value: 7
Indices of the two numbers whose sum equal to target value: 7
1 3

*/

#include <stdio.h>

#define SIZE 4  // Size of the array

int main() {
    int orig_array[SIZE] = {4, 2, 1, 5};
    int target = 7;

    printf("Original Array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d  ", orig_array[i]);
    }

    printf("\nTarget Value: %d\n", target);
    printf("Indices of the two numbers whose sum equal to target value: %d\n", target);

    // We have two loops for the two indices i and j
    for (int i = 0; i < SIZE; i++) {
        // Every outer iteration, j will start at i + 1
        // its a bruteforce aproach to find the target
        for (int j = i + 1; j < SIZE; j++) {
            if (orig_array[i] + orig_array[j] == target) {
                printf("%d %d", i, j);
                break;
            }
        }

        // =========== Tracing ===========
        //  4  2  1  5  |  i  j  |  SUM  |
        // ===============================
        //  i  j        |  0  1  |   6   |
        //  i     j     |  0  2  |   5   |
        //  i        j  |  0  3  |   9   |
        //     i  j     |  1  2  |   3   |
        //     i     j  |  1  3  |   7   | <<< Target - therefore, indices 1 and 3
        //        i  j  |  2  3  |   6   |
    }

    printf("\n");
    return 0;
}
