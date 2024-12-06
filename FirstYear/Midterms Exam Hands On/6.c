/* Write a program in C to separate odd and even integers into separate arrays. */

#include <stdio.h>

int main() {
    int length;
    printf("\nInput the number of elements to be stored in the array: ");
    scanf("%d", &length);

    // Set the array based on `length`
    int even_array[length];
    int odd_array[length];

    printf("Input %d elements in the array :\n", length);
    for (int i = 0; i < length; i++) {
        printf("element - %d : ", i);

        int input;
        scanf("%d", &input);

        // if input is even, store it in even_array
        // and set the corresponding odd_array to -1
        // to indicate that the element is empty.
        // And vice versa if the input is odd
        if (input % 2 == 0) {
            even_array[i] = input;
            odd_array[i] = -1;
        } else {
            even_array[i] = -1;
            odd_array[i] = input;
        }
    }

    // Only print the elements if its greater than -1
    // Since -1 means empty element

    printf("\nThe Even elements are : \n");
    for (int i = 0; i < length; i++) {
        int value = even_array[i];

        if (value >= 0) {
            printf("%d ", value);
        }
    }

    printf("\nThe Odd elements are : \n");
    for (int i = 0; i < length; i++) {
        int value = odd_array[i];

        if (value >= 0) {
            printf("%d ", value);
        }
    }

    printf("\n\n");
    return 0;
}
