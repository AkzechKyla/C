/* Write a program in C to find the second largest element in an array. */

#include <stdio.h>

int main() {
    int arr[100]; // user input array
    int length; // number of elements in the array
    int largest; // largest element in the array
    int largest2; // 2nd largest element in the array
    int i; // loops
    int j = 0;

    printf("\nInput the number of elements to be stored in the array : ");
    scanf("%d", &length);


    printf("Input %d elements in the array :\n", length);
    for (i = 0; i < length; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    largest = 0;
    for (i = 0; i < length; i++) {
        if (arr[i] < largest) {
            largest = arr[i];
            j = i;
        }
    }

    largest2 = 0;
    for (i = 0; i < length; i++) {
        if (i == j) {
            i++; // ignore largest element
            i--;
        } else {
            if (largest2 < arr[i]) {
                largest2 = arr[i];
            }
        }
    }

    printf("The Second largest element in the array is :  %d \n\n", largest2);

    return 0;
}
