/* 

Activities/Assessment: Unit 4 - Structure

Trace the output of the following:

*/

#include <stdio.h>
#include <conio.h>

void main() {

	struct myStruct {
		int a,b;
	};

	struct myStruct myArray[5];
	struct myStruct *p;
	int c;

	p = myArray;

	for (c = 0; c < 5; c++) {
		(p + c)-> a = c;
		(p + c)-> b = c * 2;
	}

	for (c = 0; c < 5; c++) {
		printf("%d 			%d 			%d\n", 
			c, myArray[c].a, myArray[c].b);
	}

	getch();
}

