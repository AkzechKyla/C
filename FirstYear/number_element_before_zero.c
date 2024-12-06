/* CODED BY KYLA FRANCHEZKA L. MORCILLOS */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums;
    int *ptr;
    int index = 0;
    int inputSuccess = 0;

    printf("\nHOW MANY NUMBERS WILL YOU ENTER? (Min. 5; Max. 10)\n");
    do {
        inputSuccess = scanf("%d", &nums);

        if (inputSuccess == 0) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');
        } else if (nums < 3 || nums > 10) {
            inputSuccess = 0;
            printf("Min. 5 & Max. 10 ONLY. Please try again.\n");
            while (getchar() != '\n');
        }
    } while (inputSuccess == 0);

    ptr = (int*)malloc(nums * sizeof(int));

    printf("\n\tENTER %d NUMBERS INCLUDING 0\n", nums);
    for (int i = 0; i < nums; i++) {
        inputSuccess = 0;

        do {
            printf("Number %d: ", i + 1);
            inputSuccess = scanf("%d", (ptr + i));

            if (inputSuccess == 0) {
                printf("Invalid input. Try again.\n");
                while (getchar() != '\n');
            }
        } while (inputSuccess == 0);
    }

    printf("\n");
    for (int i = 0; i < nums; i++) {
        printf("%d ", *(ptr + i));
    }

    while (*ptr) {
        if (index >= nums) {
            printf("\n!! DON'T FORGET TO INCLUDE 0 !!\n");
            return 1;
        }

        ptr++;
        index++;
    }

    printf("\n\nNumber of elements before zero: %d\n", index);
    return 0;
}
