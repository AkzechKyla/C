#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	char characterName[] = "John";
	int characterAge = 67;

	printf("There once was a man named %s\n", characterName);
	printf("he was %d years old.\n", characterAge);

	int newCharacterAge = 30;
	printf("He really liked the name %s\n", characterName);
	printf("but did not like being %d.\n", newCharacterAge);
	
	printf("Hello\"World");
	printf("\nMy favorite %s is %d", "number", 1);
	printf("\nMy favorite %s is %f", "number", 69.69); //float
	
	int favNum = 90;
	char myChar = 'i';
	printf("\nMy favorite %c is %f", myChar, favNum);
	
	//c math functions
	printf("\n%.0f", pow(2, 3)); //2 raised to the third power
	printf("\n%.0f", sqrt(36)); //square root of 36
	printf("\n%.0f", ceil(36.356)); //round up = 37
	printf("\n%f", floor(36.356)); // round down = 36
	
	/* This is an example of comments */
	/* You can use this if you want to test a code without deleting them */
	
	/*CONSTANT*/
	
	const int NUM = 5; //BIG LETTER for constants
	printf("%d\n", NUM);
	// num = 8; this will be an error because u cant modify constant
	printf("%d\n", NUM);
	
	/* GETTING USER INPUT */
	
	int age;
	printf("Enter your age: ");
	scanf("%d", &age);
	printf("You are %d years old", age);
	
	double gpa;
	printf("\nEnter your gpa: ");
	scanf("%lf", &gpa);
	printf("\nYour gpa is %f", gpa);
	
	char grade;
	printf("\nEnter your grade: ");
	scanf("%c", &grade);
	printf("\nYour gpa is %c", grade);
	
	char name[20];
	printf("\nEnter your name: ");
	scanf("%s", name);
	printf("\nYour name is %s", name);
	
	//to get input with spaces 
	char newName[20];
	printf("\nEnter your name: ");
	fgets(newName, 20, stdin); //standard input
	printf("\nYour name is %s", newName);
	// printf("Your name is %s asdfg", newName); <- will print new line

	//arrays
	int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
	luckyNumbers[1] = 200;
	printf("%d", luckyNumbers[1]);
	
	return 0;
}
