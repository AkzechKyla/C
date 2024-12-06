/* Write a program in C to find the maximum and minimum elements in an array. */

#include <stdio.h>

int main() {
    int arr[100];
    int length; // number of elements
    int i; // loops
    int max, min; //maximum and minimum elements in the array

    printf("\nInput the number of elements to be stored in the array : ");
    scanf("%d", &length);

    printf("Input %d elements in the array :\n", length);
    for (i = 0; i < length; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum element is : %d\n", max);
    printf("Minimum element is : %d\n", min);

    return 0;
}
