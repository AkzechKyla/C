/*

Activities/Assessments Lesson 6: Function

CASE STUDY 2
Write a program to call function TRIANGLE to determine if a given sides is equilateral, 
isosceles or scalene. A triangle is EQUILATERAL if all the three sides have the same 
length. ISOSCELES if only two sides have the same length and SCALENE if no sides 
have the same length. Input the length of the three sides and print whether the triangle is 
equilateral, isosceles or scalene.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* TRIANGLE(float a, float b, float c) {
    if (a == b && b == c) {
        return "EQUILATERAL\n";
    } else if (a == b || b == c || c == a) {
        return "ISOSCELES\n";
    } else {
        return "SCALENE\n";
    }
}

void classify_triangles() {

    float a, b, c;

    system("cls");
    printf("\n\tClassifying Triangles Calculator\n");
    printf("\nEnter the length of the sides of triangle in cm.\n");

    while (1) {
        printf("\tSide A: ");
        if (scanf("%f", &a) == 1 && a > 0) {
            break;
        }
        printf("Invalid input. Please try again.\n\n");
        while (getchar() != '\n');
    }

    while (1) {
        printf("\tSide B: ");
        if (scanf("%f", &b) == 1 && b > 0) {
            break;
        }
        printf("Invalid input. Please try again.\n\n");
        while (getchar() != '\n');
    }

    while (1) {
        printf("\tSide C: ");
        if (scanf("%f", &c) == 1 && c > 0) {
            break;
        }
        printf("Invalid input. Please try again.\n\n");
        while (getchar() != '\n');
    }

    char* tri_type = TRIANGLE(a, b, c);
    printf("\nThe triangle is %s", tri_type);
}

void start_input_loop() {
    // This function loops the program

    while (true) {
        int choice = 0;

        printf("\n\nWould you like to try the program again?\n");
        printf("Press 1 to continue. Press any key to exit: ");
        scanf("%d", &choice );

        if (choice == 1) {
            printf("\n");
            classify_triangles();
        } else {
            break;
        }
    }
}

int main() {

    classify_triangles();
    start_input_loop();

    return 0;
}
