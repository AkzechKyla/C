/*

Activities/Assessment: Unit 3 Pointer (3.A)

Function that separately sums the even indexed elements and odd
indexed elements of an array of doubles. Each element of the array
contributes to one of the two sums, depending on whether the index of the
element is even or odd.

*/

#include <stdio.h>

#define ARR_LEN 10

void sum(double b[]) {
    int n;
    double *sum_even;
    double *sum_odd;

    n = ARR_LEN;
    *sum_even = 0;
    *sum_odd = 0;

    for (int i = 0; i < n; i++) {
        double num = b[i];

        if (i % 2 != 0) {
            *sum_odd += num;
        } else {
            *sum_even += num;
        }
    }
    printf("Sum of odd indexed elements: %.2lf\n", *sum_odd);
    printf("Sum of even indexed elements: %.2lf\n", *sum_even);
}

int main() {
    double array[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    sum(array);
    return 0;
}
