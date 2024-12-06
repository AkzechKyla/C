/* Write a program in C to merge two arrays of the same size sorted in descending order. */

#include <stdio.h>

int main() {
    int length1, length2, length3; //number of elements in the 1st, 2nd, 3rd array
    int arr1[100], arr2[100], arr3[100]; //1st, 2nd, 3rd array
    int i, j, k; //loops
    int count = 0; //number of unique elements

    printf("Input the number of elements to be stored in the first array: ");
    scanf("%d", &length1);

    printf("\nInput %d elements in the array: \n", length1);
    for (i = 0; i < length1; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr1[i]);
    }

    printf("\nInput the number of elements to be stored in the second array: ");
    scanf("%d", &length2);

    printf("\nInput %d elements in the array: \n", length2);
    for (i = 0; i < length2; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr2[i]);
    }

    // size of merged array
    length3 = length1 + length2;

    // insert in 3rd array
    for (i = 0; i < length1; i++) {
        arr3[i] = arr1[i];
    }

    for (j = 0; j < length2; j++) {
        arr3[i] = arr2[j];
        i++;
    }

    // sort in descending order
    for (i = 0; i < length3; i++) {
        for (k = 0; k < length3 - 1; k++) {
            if (arr3[k] <= arr3[k + 1]) {
                j = arr3[k + 1];
                arr3[k + 1] = arr3[k];
                arr3[k] = j;
            }
        }
    }

    printf("\nThe merged array in decending order is :\n");
    for (i = 0; i < length3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n\n");

    return 0;
}
