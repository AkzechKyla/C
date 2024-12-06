/*

Activities/Assessments Lesson 4: Program Control Structure

Write a program that would input 3 integers and would output them in descending order.

*/

#include <stdio.h>
#include <stdlib.h>

int sort_descending(const void* a, const void* b) {
    int int_a = * ((int*) a);
    int int_b = * ((int*) b);

    if (int_a == int_b) return 0;
    else if (int_a > int_b) return -1;
    else return 1;
}

int main() {
    int ans, ints[3];

    do {
    printf("\nThis program will arrange your integers in descending order.\n\n");

        for (int i = 0; i < 3; i++) {
            int valid = 0;
            while (!valid) {
                printf("\tEnter integer %d: ", i + 1);
                if (scanf("%d", &ints[i]) == 1) {
                    valid = 1;
                } else {
                    printf("\tInvalid input. Try again.\n");
                    while (getchar() != '\n');
                }
            }
        }

        qsort(ints, 3, sizeof(int), sort_descending);

        for (int i = 0; i < 3; i++) {
            printf("\t%3d", ints[i]);
        }
    
        do {
            printf("\n\nWould you like to try again? (Type 1 if yes, and 0 if no.) ");
            scanf("%d", &ans);

            if (ans == 1 || ans == 0)
                break;
            else
                printf("\nInvalid input.\n");
                break;
        }   while (ans != 1 || ans != 0);
                printf("\nThank you for using my program.\n");
    } while (ans == 1);
    
    return 0;
}
