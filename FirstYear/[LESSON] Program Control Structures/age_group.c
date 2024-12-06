/*

Activities/Assessments Lesson 4: Program Control Structure

PROGRAMMING EXERCISE 4-1
Write a program that will determine whether a person is a child, a teen-ager or an adult 
using age as input. Assume that a child is from 0 to 12 years old, a teen-ager is from 13 
to 19 and adult is from 20 years old and above. Return ‘C’ from child, ‘T’ for teen-ager 
and ‘A’ for adult.


*/

#include <stdio.h>

int main() {
	int age, ans;

	do {
		printf("\n\nWhat age group do you belong?\n\n");
		printf("\tC for Childhood\n");
		printf("\tT for Teenager\n");
		printf("\tA for Adult\n");
		printf("\nEnter your age: ");

		if (scanf("%d", &age) != 1) {
			printf("Invalid.\n");
			return 1;
		}

		if (0 <= age && age <= 12)
		{
			printf("\nYour result is C.\n");
		}
		else if (13 <= age && age <= 19)
		{
			printf("\nYour result is T.\n");
		}
		else if (age >= 20)
		{
			printf("\nYour result is A.\n");
		}
		else
		{
			printf("\nInvalid.\n");
		}

		do { 	printf("\nWould you like to try again? (Type 1 if yes, and 0 if no.) ");
			scanf("%d", &ans);

			if (ans == 1 || ans == 0)
				break;
			else
				printf("\n Invalid input.\n");
			break;
		}

		while (ans != 1 || ans != 0);

		printf("\nThank you for using my program.\n");
	}

	while (ans == 1);

	return 0;
}
