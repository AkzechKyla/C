/* Write a program in C to sort an array using a pointer. */

#include <stdio.h>
#include <stdlib.h>

void sortArray(int *arr, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(arr + j) < *(arr + i)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int main() {
    int size, i;
    printf("Input the number of elements to store in the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("Input %d number of elements in the array:\n", size);
    for (i = 0; i < size; i++) {
        printf("element - %d: ", i + 1);
        scanf("%d", arr + i);
    }

    sortArray(arr, size);

    printf("\nThe elements in the array after sorting:\n");
    for (i = 0; i < size; i++) {
        printf("element - %d: %d\n", i + 1, *(arr + i));
    }

    free(arr);
    return 0;
}
