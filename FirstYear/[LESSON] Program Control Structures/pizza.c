/*

Activities/Assessments Lesson 4: Program Control Structure

Pizza parlors offers different pizza sizes in terms of diameters. For example, Domino’s 
has three options: 10 inches, 12 inches, 14 inches diameter. Extravaganza pizza costing 
178 pesos, 259 pesos and 314 pesos respectively. Write a program that will input the 
diameter of the pizza, and its price. Determine the (a) area of the pizza and (b) the price 
by the divided area. Find out which of the three options above (for Domino’s) is the least 
expensive in terms of price per square inch of pizza. Note that the area of a circle is 
equivalent to PI* (diameter / 2)2.

*/

#include<stdio.h>
#include<math.h>

//10 inch - 178
//12 inch - 259
//14 inch - 314

void pizza_info1(int *diameter, int *price) {
	
	printf("\n\t\tWelcome to DOMINO'S PIZZA\n");
	printf("\nPIZZA 1");
	printf("\n\tEnter the diameter of the pizza in inches: ");
	scanf("%d", diameter);
	printf("\tEnter the price of the pizza in pesos: ");
	scanf("%d", price);
}

void pizza_info2(int *diameter, int *price) {
	
	printf("\nPIZZA 2");
	printf("\n\tEnter the diameter of the pizza in inches: ");
	scanf("%d", diameter);
	printf("\tEnter the price of the pizza in pesos: ");
	scanf("%d", price);
}

void pizza_info3(int *diameter, int *price) {
	
	printf("\nPIZZA 3");
	printf("\n\tEnter the diameter of the pizza in inches: ");
	scanf("%d", diameter);
	printf("\tEnter the price of the pizza in pesos: ");
	scanf("%d", price);
}

double calculate_area(int diameter) {
	
	double radius = diameter / 2.0;
	double area = M_PI * (radius * radius);
	return area;
}

double calculate_square(double area, int price) {
	
	double square_inch = (double)price / area;
	return square_inch;
}

int main() {
	
	int pizza10, pizza10_price;
	int pizza12, pizza12_price;
	int pizza14, pizza14_price;
	
	pizza_info1(&pizza10, &pizza10_price);
	pizza_info2(&pizza12, &pizza12_price);
	pizza_info3(&pizza14, &pizza14_price);
	
	double pizza10_area = calculate_area(pizza10);
	double pizza12_area = calculate_area(pizza12);
	double pizza14_area = calculate_area(pizza14);
	
	double pizza10_square = calculate_square(pizza10_area, pizza10_price);
	double pizza12_square = calculate_square(pizza12_area, pizza12_price);
	double pizza14_square = calculate_square(pizza14_area, pizza14_price);
	
	double square_inch[3] = {pizza10_square, pizza12_square, pizza14_square};
	double min_price = square_inch[0];
	
	int i;
	for (i = 1; i < 3; i++) {
		
		if (square_inch[i] < min_price) {
			min_price = square_inch[i];
		}
	}
	
	printf("\t\nPIZZA PRICES (PER SQUARE INCHES)\n\n");
	printf("\tPIZZA 1: Php%.2lf\n", pizza10_square);
	printf("\tPIZZA 2: Php%.2lf\n", pizza12_square);
	printf("\tPIZZA 3: Php%.2lf\n", pizza14_square);
	
	if (min_price == pizza10_square) {
		printf("\n10-inch pizza is the least expensive.\n");
	}
	else if (min_price == pizza12_square) {
		printf("\n12-inch pizza is the least expensive.\n");
	}
	else {
		printf("\n14-inch pizza is the least expensive.\n");
	}
	
	return 0;
}
