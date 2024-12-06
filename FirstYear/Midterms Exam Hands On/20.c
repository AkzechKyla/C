#include <stdio.h>

int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    int size, i;
    printf("Input the number of elements to store in the array (max 10): ");
    scanf("%d", &size);

    if (size <= 0 || size > 10) {
        printf("Invalid input. Please enter a number between 1 and 10.\n");
        return 0;
    }

    int arr[10];
    printf("Input %d number of elements in the array:\n", size);
    for (i = 0; i < size; i++) {
        printf("element - %d: ", i + 1);
        scanf("%d", arr + i);
    }

    int sum = sumArray(arr, size);

    printf("\nThe sum of array is: %d\n", sum);

    return 0;
}
