/*

Activities/Assessments Lesson 6: Function

CASE STUDY 3 Military Time

General Program Definition
In military, when one gives a time it is usually in a 24-hour notation (e.g. 1300 
means 1:00PM). Write a program that converts from 24-hour notation to 12-hour notation 
using function.

Input Specifications 
The input must be a single integer ranging from 0 to 2400. Any other value must 
result into an input error which the program should display as a message to the user 
before it halts program execution.

Output Specifications
Output the time in 12-hour notation using the following format: 1:00 PM using a 
colon to separate the hour part from the minute part and adding the abbreviations AM or 
PM to indicate what part of the day it is. Note that you must observe the 2-digit display.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void convert_time(int time) {
    int hour = time / 100;
    int minute = time % 100;

    printf("\n\tRegular Time:");
    if (hour == 0) {
        printf("\n\t12:%02d AM", minute);
    } else if (hour < 12) {
        printf("\n\t%d:%02d AM", hour, minute);
    } else if (hour == 12) {
        printf("\n\t12:%02d PM", minute);
    } else {
        printf("\n\t%d:%02d PM", hour - 12, minute);
    }
    printf("\n");
}

void ask_for_time() {
    int time;

    system("cls");
    printf("\n\tMILITARY TIME CONVERTER\n");

    while (true) {
        printf("Enter time in 24-hour notation (0-2400): ");
        scanf("%d", &time);

        int hour = time / 100;
        int minute = time % 100;

        if (time < 0 || time > 2400) {
            printf("\nEnter military time between 0000 to 2400 only. Try again.\n");
        } else if (minute >= 60) {
            printf("\nEnter a valid time (minute must be less than 60). Try again.\n\n");
        } else {
            convert_time(time);
            break;
        }
    }
}


void start_input_loop() {
    // This function loops the program

    while (true) {
        int choice = 0;

        printf("\n\nWould you like to convert time again?\n");
        printf("Press 1 to continue. Press any key to exit: ");
        scanf("%d", &choice );

        if (choice == 1) {
            printf("\n");
            ask_for_time();
        } else {
            break;
        }
    }
}

int main() {

    ask_for_time();
    start_input_loop();

    return 0;
}
