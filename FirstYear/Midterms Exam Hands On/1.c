/* Write a program in C to count the total number of duplicate elements in an array. */

#include <stdio.h>

int main() {
    int length; //number of elements in the array
    int arr[100]; //array
    int i, j; //loops
    int dupes = 0; //number of dupes

    printf("\nInput the number of elements to be stored in the array: ");
    scanf("%d", &length);

    printf("\nInput %d elements in the array: \n", length);
    for (i = 0; i < length; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // COUNT THE TOTAL NUMBER OF DUPLICATES IN THE ARRAY
    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[j] == arr[i]) {
                dupes++;
            }
        }
    }

    printf("Total number of duplicate elements found in the array is: %d", dupes);

    return 0;
}
