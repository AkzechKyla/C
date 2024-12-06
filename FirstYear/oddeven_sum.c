/*

Activities/Assessment: Unit 3 Pointer (3.B)

Function that computes two sums from the elements of an array of 
integers. Each element of the array contributes to one of the two sums, 
depending on whether the element itself is even or odd. 

*/

#include <stdio.h>

#define ARR_LEN 10

void sum(int x[]) {
    int n;
    int sum_even;
    int sum_odd;

    n = ARR_LEN;
    sum_even = 0;
    sum_odd = 0;

    for (int i = 0; i < n; i++) {
        int num = x[i];

        if (num % 2 == 0) {
            sum_even += num;
        } else {
            sum_odd += num;
        }
    }

    printf("Sum of even indexed elements: %d\n", sum_even);
    printf("Sum of odd indexed elements: %d\n", sum_odd);
}

int main() {
    int array[ARR_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    sum(array);
    return 0;
}
