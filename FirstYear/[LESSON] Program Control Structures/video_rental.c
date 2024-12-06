/*

Activities/Assessments Lesson 4: Program Control Structure

A Video Rental gives a fine to their customers who return the CDs of tape later than 
the due date. Input the number of days late and display the fine. 
Days Fine
< = 2 10.00
<= 4 15.00
<= 5 20.00
>= 7 Equal to the amount of rent (CD = 
50.00 / VHS = 35.00 )

*/

#include <stdio.h>

int main() {
    int tape, days_late;

    printf("\n\tTape Rental Services\n\n");
    printf("Input numbers of days late returned: ");
    scanf("%d", &days_late);

    if (days_late <= 0) {
        printf("No fine.\n");
    } else if (days_late <= 2) {
        printf("You will pay a fine of Php10.00\n");
    } else if (days_late <= 4) {
        printf("You will pay a fine of Php15.00\n");
    } else if (days_late <= 6) {
        printf("You will pay a fine of Php20.00\n");
    } else if (days_late >= 7) {
        printf("Which type of tape did you rent? (Enter the number)\n");
        printf("\t(1) CD\n\t(2) VHS\n");
        printf("\t = ");
        scanf("%d", &tape);
        
        if (tape == 1) {
            printf("\nYou will pay a fine of Php50.00\n");
        } else if (tape == 2) {
            printf("\nYou will pay a fine of Php35.00\n");
        } else
            printf("Invalid type of tape.\n");
    }

    return 0;
}
