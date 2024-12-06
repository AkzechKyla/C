#include <stdio.h>
#include <stdbool.h>

#define INVENTORY_SIZE 51
#define MIN_SHOE_SIZE 3
#define MAX_SHOE_SIZE 5  // TODO: 14
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

int is_file_exist() {
	file_ptr = fopen(INVENTORY_FILE, "a");

	if (file_ptr == NULL) {
		printf("\nFAILED TO OPEN THE FILE.\n");
		fclose(file_ptr);
		return 0;
	}

	fclose(file_ptr);
	return 1;
}

void write_inventory() {
	file_ptr = fopen(INVENTORY_FILE, "w");

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

bool validate_range_input(int input, int min, int max) {
	if (input > max || input < min) return false;
	return true;
}

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

int get_style_number() {
	int style_number = get_range_input(0, INVENTORY_SIZE - 1, "\n Style number (0-50): ");
	int stock_index = search_by_style(style_number);

	if (stock_index != -1) {
		printf("The given style number has already been assigned to shoe stock #%d.", stock_index);
		return get_style_number();
	}

	return style_number;
}

void enter_new_record() {
	if (stock_index >= INVENTORY_SIZE) {
		printf("\nInventory is full. Cannot add more records.\n");
		return;
	}

	printf("\nENTER A NEW RECORD\n\n");

	inventory[stock_index].stock_number = stock_index + 1;
	printf("\n Stock #%d\n", inventory[stock_index].stock_number);

	// Set style_number
	inventory[stock_index].style_number = get_style_number();

	// Set pairs_count_per_size
	for (int i = 0; i < PAIRS_COUNT_LEN; i++) {
		printf(" *Size %d:\n", i + MIN_SHOE_SIZE);
		int pairs_count = get_range_input(0, 9999, "  Amount: ");
		inventory[stock_index].pairs_count_per_size[i] = pairs_count;
	}

	// Set price
	inventory[stock_index].price = get_positive_float("Price: $");

	stock_index++;
	write_inventory();

	printf("\n [1] Enter another record\n");
	printf(" [2] Back to main menu\n");

	if (get_range_input(1, 2, "~") == 2) return;
	return enter_new_record();
}

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

void display_record() {
	printf("\nDISPLAY A RECORD\n\n");
	print_shoe_stock(get_stock_index());
	printf("\n [1] Display another record\n");
	printf(" [2] Back to main menu\n");

	if (get_range_input(1, 2, "~") == 1) {
		return display_record();
	} else {
		return;
	}
}

void change_price() {
	printf("\nCHANGE PRICE\n\n");
	int index = get_stock_index();
	
	printf("\n\n Current Price: $%.2f\n", inventory[index].price);
	inventory[index].price = get_positive_float(" Enter New Price: $");
	
	write_inventory();
	printf("\n Price updated successfully!\n\n");

	printf("\n [1] Change another price\n");
	printf(" [2] Back to main menu\n");

	if (get_range_input(1, 2, "~") == 1) {
		return change_price();
	} else {
		return;
	}
}

void change_stock_onhand(int stock_index) {
	int size = get_range_input(MIN_SHOE_SIZE, MAX_SHOE_SIZE, "\n Enter the size to change the stock on hand: ");
	
	printf(" Enter the new quantity for size %d: ", size);

	inventory[stock_index].pairs_count_per_size[size - MIN_SHOE_SIZE] = get_range_input(0, 9999, "");
	
	write_inventory();
	printf("\n Stock on hand for size %d updated successfully!\n\n", size);
	
	printf(" [1] Change the number on hand of the same stock\n");
	printf(" [2] Change the number on hand of a different stock\n");
	printf(" [3] Back to the main menu\n");

	int input = get_range_input(1, 3, "~");
	
	if (input == 1) {
		change_stock_onhand(stock_index);
	} else if (input == 2) {
		return change_stock_onhand(get_stock_index());
	} else {
		return;
	}
}

void delete_record() {
	if (stock_index == 0) {
		printf("\n There are no more records to be deleted.\n");
	} else {
		int index = get_stock_index();
		
		printf("\n Do you really want to delete the record?\n");
		printf("\n [1] Yes\n");
		printf(" [2] No\n");

		if (get_range_input(1, 2, "~") == 2) return;

		for (int i = 0; i < stock_index; i++) {
			if (i >= index) {
				inventory[i] = inventory[i + 1];
				inventory[i].stock_number = i + 1;
			}
		}
		
		stock_index--;
		write_inventory();
		
		printf("\n Record has been successfully deleted.\n");
	}

	printf("\n [1] Delete another record\n");
	printf(" [2] Back to the main menu\n");

	if (get_range_input(1, 2, "~") == 2) return;
	return delete_record();
}

int main() {
	if (!is_file_exist()) return 1;
	read_inventory();

	int input;

	while (true) {
		printf("\nShoe Store Inventory Management\n");
		printf("\nOptions:\n");
		printf("  [1] Enter a new record                 \n");
		printf("  [2] Display a record                   \n");
		printf("  [3] Change the price of a stock item   \n");
		printf("  [4] Change the number on hand          \n");
		printf("  [5] Delete a record                    \n");
		printf("  [6] Exit                               \n");

		input = get_range_input(1, 6, "~");
		
		if (stock_index == 0) {
			if (input > 1 && input < 6) {
				printf("\nENTER RECORD FIRST!!!\n");
				continue;
			}
		}

		switch (input) {
			case 1:
				enter_new_record();
				break;
			case 2:
				display_record();
				break;
			case 3:
				change_price();
				break;
			case 4:
				printf("\nCHANGE STOCK ON HAND\n\n");
				change_stock_onhand(get_stock_index());
				break;
			case 5:
				delete_record();
				break;
			case 6:
				printf("\n Do you really want to exit the program?\n\n [1] Yes\n [2] No\n");
				input = get_range_input(1, 2, "~");

				if (input == 1) {
					printf("\n Thank you for using the Shoe Store Inventory Management system!\n");
					return 0;
				}
		}
	}

	return 0;
}
