/* Write a program in C to count the frequency of each element of an array. */

#include <stdio.h>

int main() {
    int arr[100], freq[100];
    int length; // mumber of elements in the array
    int i, j; // loops
    int count; // count

    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &length);

    printf("Input %d elements in the array :\n", length);
    for (i = 0; i < length; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);

        freq[i] = -1;
    }

    for (i = 0; i < length; i++) {
        count = 1;
        for (j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0;
            }
        }

        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    printf("\nThe frequency of all elements of array : \n");
    for (i = 0; i < length; i++) {
        if (freq[i] != 0) {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }

    return 0;
}
