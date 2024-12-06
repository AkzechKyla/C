/*

Activities/Assessments Lesson 6: Function

PROGRAMMING EXERCISES 6-5
Four track stars have entered the mile race at the Penn Relays. Write a program that 
scans in the race time in minutes and seconds for a runner and computes and displays 
the speed in feet per seconds and in meters per seconds. 
Hint: there are 5280 feet in one mile, and one kilometer equals 3282 feet.
Write and call a function that displays instructions to the program users.

*/

#include <stdio.h>
#include <stdlib.h>

#define FEET_PER_MILE 5280
#define FEET_PER_METER 3.282

void display_instructions() {
    printf("\nFour track stars have entered the mile race at the Penn Relays.\n");
    printf("\nEnter the race time in minutes and seconds for each runner.\n");
    printf("The program will compute and display the speed in feet per second and meters per second.\n\n");
}

void compute_speed(int minutes, int seconds) {
    float speed_in_feet_per_second, speed_in_meters_per_second;

    float total_seconds = minutes * 60 + seconds;
    speed_in_feet_per_second = FEET_PER_MILE / total_seconds;
    speed_in_meters_per_second = (FEET_PER_MILE / FEET_PER_METER) / total_seconds;

    printf("\nSpeed in feet per second: %.2f ft/s\n", speed_in_feet_per_second);
    printf("Speed in meters per second: %.2f m/s\n", speed_in_meters_per_second);
}

void track_record() {
    int minutes, seconds;

    system("cls");
    printf("\n\tPENN RELAYS - TRACK RECORD\n");

    display_instructions();

    for (int i = 1; i <= 4; i++) {
        int is_input_success;

        printf("\n[Runner %d]\n", i);
        do {
            printf("\tMinute/s: ");
            is_input_success = scanf("%d", &minutes);

            if (is_input_success == 0 || minutes < 0) {
                printf("Invalid input. Please type the number of minutes only.\n");
                while (getchar() != '\n');
            } 
        } while (is_input_success == 0 || minutes < 0);

        is_input_success == 1;
        do {
            printf("\tSecond/s: ");
            is_input_success = scanf("%d", &seconds);

            if (is_input_success == 0 || seconds < 0) {
                printf("Invalid input. Please type the number of seconds only.\n");
                while (getchar() != '\n');
            }
        } while (is_input_success == 0 || seconds < 0);
        compute_speed(minutes, seconds);
    }
}

int main() {

    track_record();

    return 0;
}
