/*

Activities/Assessments Lesson 4: Program Control Structure

An applicant will be accepted to the Jedi Knight Academy if he is at least 200 cm tall; age 
is between 21 and 25 inclusive, and a citizen of the Planet Endor. However, if the 
applicant is recommendee of Jedi Master Obi Wan, he is accepted automatically 
regardless of his height, age and citizenship. Write a program that would input the 
applicant’s height, age, citizenship code (1- citizen 0-not citizen) and recommendee’s 
code (1- recommended 0- not recommended) and then output whether the applicant is 
accepted or rejected.

*/

#include <stdio.h>

int main() {
    float height;
    int age;
    int ct_code;
    int rc_code;
    
    printf("\n\tJedi Knight Academy - Application Form\n");

    printf("\nAre you a recommendee of Jedi Master Obi Wan? (Yes = 1, No = 0) ");
    scanf("%d", &rc_code);

    if (rc_code == 1) {
        printf("\nCongratulations! You are automatically accepted to the academy.\n");
        return 0;
    }

    printf("Are you a citizen of Planet Endor? (Yes = 1, No = 0): ");
    scanf("%d", &ct_code);

    printf("Height (cm): ");
    scanf("%f", &height);

    printf("Age: ");
    scanf("%d", &age);

    if (height >= 200) {
        if (age >= 21 && age <= 25) {
            if (ct_code == 1) {
                printf("\nCongratulations! You are accepted.");
                return 0;
            }
        }
    }

    printf("\nSorry, but you didn't qualify in one of our pre-requisites.\n");
    printf("\t(1) Must be at least 200 cm tall\n");
    printf("\t(2) Must be 21-25 years old\n");
    printf("\t(3) Must be a Planet Endor citizen\n");
    return 0;
}
