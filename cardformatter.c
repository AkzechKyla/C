#include <stdio.h>
#include <stdbool.h>

#define SERIES_FILE "series.txt"

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

bool validate_range_input(int input, int min, int max) {
	if (input > max || input < min) return false;
	return true;
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

int ask_user_feature() {
	int input;

		printf("+---------------------------------------------------+\n");
		printf("| 				DISCORD BOT FORMATTER				|\n");
		printf("+---------------------------------------------------+\n");
		printf("|\tWhich feature do you want to use?           		|\n");
		printf("|\t[1] Card Code Formatter			           		|\n");
		printf("|\t[2] Card Hunting Formatter	               		|\n");
		printf("+---------------------------------------------------+\n");
		printf("\n");
	
	input = get_range_input(1, 3, ">>> ");
	
	return input;
}

int main() {
	if (!is_file_exist()) return 1;
	// read_inventory(); // todo

	int input, feature;

	while (true) {
		printf("+---------------------------------------------------+\n");
		printf("| 				DISCORD BOT FORMATTER				|\n");
		printf("+---------------------------------------------------+\n");
		printf("|\tWhich discord bot are you using?            		|\n");
		printf("|\t[1] Tofu			                           		|\n");
		printf("|\t[2] Karuta	                               		|\n");
		printf("|\t[3] Exit                                    		|\n");
		printf("+---------------------------------------------------+\n");
		printf("\n");

		input = get_range_input(1, 3, ">>> ");

		switch (input) {
			case 1:
				feature = ask_user_feature();
				break;
			case 2:
				feature = ask_user_feature();
				break;
			default:
				printf("\nProgram exiting...\n");
		}
	}

	return 0;
}
