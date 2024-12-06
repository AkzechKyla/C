#include <stdio.h>
#include <stdbool.h>

#define INVENTORY_SIZE 51
#define MIN_SHOE_SIZE 3
#define MAX_SHOE_SIZE 14  // TODO: 14
#define PAIRS_COUNT_LEN MAX_SHOE_SIZE - MIN_SHOE_SIZE + 1
#define INVENTORY_FILE "inventory.txt"

FILE *file_ptr;

struct ShoeStock {
	int stock_number;
	int style_number;
	int pairs_count_per_size[PAIRS_COUNT_LEN];
	float price;
};

struct ShoeStock inventory[INVENTORY_SIZE];
int stock_index = 0;

/* A function to validate whether an input value is within a specified range (min to max) */
bool validate_range_input(int input, int min, int max) {
	if (input > max || input < min) return false;
	return true;
}

/* A function to get a positive floating-point number from the user.
It uses recursion to prompt for input until a valid value is provided */
float get_positive_float(char message[100]) {
	// If first character is "~", then use the default message value
	if (message[0] == '~') {
		printf("\n Please enter positive float: ");
	} else {
		printf("%s", message);
	}

	float input;

	if (scanf("%f", &input) != 1 || input < 0) {
		printf(" Invalid input. Please enter non-negative numbers only!\n");
		while (getchar() != '\n');  // Clear input buffer
		return get_positive_float(message);
	}

	return input;
}

/* A function to get an integer input from the user within a specified range (min to max). 
It also uses recursion to ensure a valid input is provided. */
int get_range_input(int min, int max, char message[100]) {
	// If first character is "~", then use the default message value
	if (message[0] == '~') {
		printf("\n Please enter your choice (%d-%d): ", min, max);
	} else {
		printf("%s", message);
	}

	int input;
	scanf("%d", &input);

	bool is_valid = validate_range_input(input, min, max);

	if (!is_valid) {
		printf("Invalid input. Please enter numbers from %d-%d only!\n", min, max);
		while (getchar() != '\n');  // Clear input buffer
		return get_range_input(min, max, message);
	}

	return input;
}

int search_by_style(int style_number) {
	for (int i = 0; i < stock_index; i++) {
		if (inventory[i].style_number == style_number) {
			return i;
		}
	}

	return -1;
}

int search_by_stock(int stock_number) {
	for (int i = 0; i < stock_index; i++) {
		if (inventory[i].stock_number == stock_number) {
			return i;
		}
	}

	return -1;
}

/* A function responsible for getting a unique style number for a new shoe stock. */
int get_style_number() {
	int style_number = get_range_input(0, INVENTORY_SIZE - 1, "\n Style number (0-50): ");
	int stock_index = search_by_style(style_number);

	if (stock_index != -1) {
		printf("The given style number has already been assigned to shoe stock #%d.", stock_index);
		return get_style_number();
	}

	return style_number;
}

/* A function to check if the file "inventory.txt" exists and can be opened for read.
If the file opening fails, it displays an error message and returns 0. */
int is_file_exist() {
	file_ptr = fopen(INVENTORY_FILE, "r");

	if (file_ptr == NULL) {
		printf("\nFAILED TO OPEN THE FILE.\n");
		fclose(file_ptr);
		return 0;
	}

	fclose(file_ptr);
	return 1;
}

/* A function used to the existing inventory data from the text file into the program's memory. 
It opens the file in read mode, reads the stock details, and closes the file. */
void read_inventory() {
	file_ptr = fopen(INVENTORY_FILE, "r");

	fscanf(file_ptr, "TOTAL NUMBER OF STOCK: %d\n", &stock_index);

	for (int i = 0; i < stock_index; i++) {
		fscanf(file_ptr, "Stock #%d\n", &inventory[i].stock_number);
		fscanf(file_ptr, "Style Number: %d\n", &inventory[i].style_number);
		for (int j = 0; j < PAIRS_COUNT_LEN; j++) {
			char string[10];
			fscanf(file_ptr, "%[*Size] %s %d\n", &string, &string, &inventory[i].pairs_count_per_size[j]);
		}
		fscanf(file_ptr, "Price: $%f\n", &inventory[i].price);
	}

	fclose(file_ptr);
}

/* A function used to write the current inventory data into the text file.
It opens the file in write mode, writes the stock details one by one, and then closes the file.*/
void write_inventory() {
	file_ptr = fopen(INVENTORY_FILE, "w");
	if (file_ptr == NULL) {
		printf("\nFAILED TO OPEN THE FILE.\n");
		return;
	}
	
	fprintf(file_ptr, "TOTAL NUMBER OF STOCK: %d\n", stock_index);
	for (int i = 0; i < stock_index; i++) {
		fprintf(file_ptr, "Stock #%d\n", inventory[i].stock_number);
		fprintf(file_ptr, "Style Number: %d\n", inventory[i].style_number);
		for (int j = 0; j < PAIRS_COUNT_LEN; j++) {
			fprintf(file_ptr, "*Size %d: %d\n", j + MIN_SHOE_SIZE, inventory[i].pairs_count_per_size[j]);
		}
		fprintf(file_ptr, "Price: $%.2f\n", inventory[i].price);
	}

	fclose(file_ptr);
}

/* A function used to print details of the shoe stock at that index in the inventory. */
void print_shoe_stock(int index) {
	printf(" Stock Number: %d\n", inventory[index].stock_number);
	printf(" Style Number: %d\n", inventory[index].style_number);

	printf("+--------------------------------+\n");
	printf("|  Number of pairs in each size  |\n");
	printf("+----------+---------------------+\n");
	printf("| Size     | Number of Pairs     |\n");
	for (int i = 0; i < PAIRS_COUNT_LEN; i++) {
		printf("+----------+---------------------+\n");
		printf("| %-8d | %-19d |\n", i + MIN_SHOE_SIZE, inventory[index].pairs_count_per_size[i]);
	}
	printf("+----------+---------------------+\n");

	printf("\n Price: $%.2f\n", inventory[index].price);
}

/* A function that allows the user to search for a shoe stock 
by either the stock number or the style number */
int get_stock_index() {
	printf(" [1] Search by Stock Number\n");
	printf(" [2] Search by Style Number\n");
	
	int input = get_range_input(1, 2, "~");
	int index;
	
	if (input == 1) {
		index = search_by_stock(get_range_input(0, INVENTORY_SIZE - 1, " Enter Stock Number: "));
	} else {
		index = search_by_style(get_range_input(0, INVENTORY_SIZE - 1, " Enter Style Number: "));
	}

	if (index == -1) {
		printf("\n Record does not exist.\n\n");
		return get_stock_index();
	}

	return index;
}

/* A function that allows the user to view the details of a specific shoe stock*/
void display_record() {
	print_shoe_stock(get_stock_index());
	printf("\n [1] Display another record\n");
	printf(" [2] Back to main menu\n");

	if (get_range_input(1, 2, "~") == 1) {
		return display_record();
	} else {
		return;
	}
}

int main() {
	if (!is_file_exist()) return 1;
	read_inventory();
	int input;

	while (1) {
		printf("\n-------------------------------------------\n");
		printf("|     Shoe Store Inventory Management     |\n");
		printf("-------------------------------------------\n");
		printf("|           DISPLAY A RECORD              |\n");
		printf("-------------------------------------------\n");

		display_record();

		printf("\n Do you really want to exit the program?\n\n [1] Yes\n [2] No\n");
		input = get_range_input(1, 2, "~");

		if (input == 1) {
			printf("\n Thank you for using the Shoe Store Inventory Management system!\n");
			return 0;
		}
	}

	return 0;
}
