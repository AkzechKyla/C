/* Write a program in C to print all unique elements in an array. */

#include <stdio.h>

int main() {
    int length; //number of elements in the array
    int arr[100]; //array
    int i, j; //loops
    int count = 0; //number of unique elements

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &length);

    printf("\nInput %d elements in the array: \n", length);
    for (i = 0; i < length; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // PRINT ALL UNIQUE ELEMENTS IN THE ARRAY
    printf("\nThe unique elements found in the array are: \n");
    for (i = 0; i < length; i++) {
        count = 0;
        for (j = 0 ; j < length; j++) {
            if (i != j) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
        }

        if (count == 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n\n");

    return 0;
}
