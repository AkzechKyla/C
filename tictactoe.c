#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __unix__
#include <unistd.h>
#endif



#define WHITE      "\x1b[97m"
#define RED        "\x1b[31m"
#define GREEN      "\x1b[32m"
#define YELLOW     "\x1b[33m"
#define BLUE       "\x1b[34m"
#define MAGENTA    "\x1b[35m"
#define CYAN       "\x1b[36m"
#define ANSI_RESET "\x1b[0m"



void cool_print(char *color, int delay, char *format, ...) {
	char *string = (char *) malloc(100 * sizeof(char));
	va_list args;

	va_start(args, format);
	vsprintf(string, format, args);
	va_end(args);

	printf("%s", color);

	for (int i = 0; i < strlen(string); i++) {
		printf("%c", string[i]);
		fflush(stdout);

		#ifdef _WIN32
		Sleep(delay);
		#endif

		#ifdef __unix__
		usleep(delay * 1000);
		#endif
	}

	printf("%s", ANSI_RESET);
}


void display_board(int board[3][3]) {
	for (int i = 0; i < 3; i++) {
		char c1[2], c2[2], c3[2];
		
		if (board[i][0] == 1) {
			strncpy(c1, "X", 2);
		} else if (board[i][0] == 2) {
			strncpy(c1, "O", 2);
		} else {
			strncpy(c1, " ", 2);
		}
		
		if (board[i][1] == 1) {
			strncpy(c2, "X", 2);
		} else if (board[i][1] == 2) {
			strncpy(c2, "O", 2);
		} else {
			strncpy(c2, " ", 2);
		}
		
		if (board[i][2] == 1) {
			strncpy(c3, "X", 2);
		} else if (board[i][2] == 2) {
			strncpy(c3, "O", 2);
		} else {
			strncpy(c3, " ", 2);
		}

		cool_print(WHITE, 0, "\n\t       [%s] [%s] [%s]\n", c1, c2, c3);
	}
}

void against_computer_actions(int board[3][3]) {
	int computer_action;
	int possible_actions[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	while (1) {
		computer_action = possible_actions[rand() % 9];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int pos = i + j + (1 + i * 2);
				
				if (pos == computer_action && board[i][j] == 0) { //check if position is empty
					board[i][j] = 2; //mark as computer's action
					break;
				}
			}
		}
		display_board(board);
	}
}

void play_against_computer() {
	// 0 for empty
	// 1 for player
	// 2 for computer
	int board[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	int position;

	cool_print(WHITE, 30, "\t---PLAYING AGAINST COMPUTER---\n");

	cool_print(WHITE, 30, "\n\t       [ ] [ ] [ ]\n");
	cool_print(WHITE, 30, "\n\t       [ ] [ ] [ ]\n");
	cool_print(WHITE, 30, "\n\t       [ ] [ ] [ ]\n");
	cool_print(WHITE, 30, "\nYou are playing as X. Choose your position (between 1-9).\n");
	cool_print(WHITE, 30, "\n\t       [1] [2] [3]\n");
	cool_print(WHITE, 30, "\n\t       [4] [5] [6]\n");
	cool_print(WHITE, 30, "\n\t       [7] [8] [9]\n");

	while (1) {
		cool_print(WHITE, 30, "Position = ");
		scanf("%d", &position);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int pos = i + j + (1 + i * 2);
				
				if (pos == position) {
					board[i][j] = 1;
				}
			}
		}
		
		display_board(board);
		against_computer_actions(board);
	}
}

void show_rules() {
	
	cool_print(YELLOW, 30, "\n   TIC-TAC-TOE (Command Prompt Version)\n");
	cool_print(WHITE, 30, "\n\tRULES FOR PLAYING THE GAME:\n");
	cool_print(WHITE, 30, "\nThe program will show a box of TIC-TAC-TOE \n");
	cool_print(WHITE, 30, "and the player must type the corresponding \nnumber of the box they want to put their move.\n");
	cool_print(WHITE, 30, "\n\t       [1] [2] [3]\n");
	cool_print(WHITE, 30, "\n\t       [4] [5] [6]\n");
	cool_print(WHITE, 30, "\n\t       [7] [8] [9]\n");
	
}

void select_player() {
	int player;
	
	cool_print(WHITE, 30, "\nChoose who to play against with:\n");
	cool_print(WHITE, 30, "\n\t1. computer\n");
	cool_print(WHITE, 30, "\t2. another player\n");
	cool_print(WHITE, 30, "\t= ");
	scanf("%d", &player);
	
	if (player == 1) {
		cool_print(WHITE, 30, "\nGot it! You want to play against computer.\n");
		cool_print(WHITE, 30, "Game starting. . .\n");
		play_against_computer();
	} else if (player == 2) {
		cool_print(WHITE, 30, "Goodluck to the both of you!\n");
		cool_print(WHITE, 30, "Game starting. . .\n");
	} else {
		cool_print(WHITE, 30, "Invalid input. The program will exit.\n");
	}

}

void start_game() {
	int choice = 0;
	
	cool_print(WHITE, 30, "\nAre you ready to start the game?\n");
	cool_print(WHITE, 30, "Press 1 to start the game. \nPress 2 to exit the program.\n");
	cool_print(WHITE, 30, "\n\t1. Start\n");
	cool_print(WHITE, 30, "\t2. Exit\n\n");
	cool_print(WHITE, 30, "\t= ");
	scanf("%d", &choice);
	
	if (choice == 1) {
		select_player();
	} else if (choice == 2) {
		cool_print(WHITE, 30, "\nProgram exiting. . . .\n");
	} else {
		cool_print(WHITE, 30, "\nInvalid input.\n");
	}
}

int main() {

	show_rules();
	start_game();

	return 0;
}
