#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 10
#define MAX_RATINGS 5

void display_ratings(int **ratings, int num_movies, int num_ratings) {
	
	printf("\nMovie ratings: \n");
	for (int i = 0; i < num_movies; i++) {
		printf("Movie %d: ", i + 1);
		for (int j = 0; j < num_ratings; j++) {
			printf("%d ", *(*(ratings + i) + j));
		}
		printf("\n");
	}
	
	printf("\nAverage ratings: \n");
	for (int i = 0; i < num_movies; i++) {
		int total_rating = 0;
		float average_rating = 0;

		printf("Movie %d: ", i + 1);
		for (int j = 0; j < num_ratings; j++) {
			total_rating += *(*(ratings + i) + j);
		}
		
		average_rating = ((float)total_rating / (float)num_ratings);
		
		printf("%.2f", average_rating);
		printf("\n");
	}
}

void enter_ratings(int **ratings, int num_movies, int num_ratings) {
	int success_input;

	printf("\nINSTRUCTION: Enter ratings on a scale of 1 to 5 only.\n");
	for (int i = 0; i < num_movies; i++) {
		printf("\nMovie %d:\n", i + 1);
		for (int j = 0; j < num_ratings; j++) {
			do {
				success_input = 0;

				printf("Enter rating %d: ", j + 1);
				success_input = scanf("%d", (*(ratings + i) + j));
				
				if (success_input != 1) {
					printf("Invalid input. Please enter a number only.\n");
				} else if (*(*(ratings + i) + j) <= 0 || *(*(ratings + i) + j) > MAX_RATINGS) {
					printf("Invalid input. Please a rating on a scale of 1 to 5 only.\n");
				}
				
				while (getchar() != '\n');
				
			} while (success_input != 1 || *(*(ratings + i) + j) <= 0 || *(*(ratings + i) + j) > MAX_RATINGS);
		}
	}
}

int main() {
	int **movie_ratings; //2D array
	int num_movies; //number of movies
	int num_ratings; //number of ratings per movie
	int success_value;
	int try_again;
	
	do {
		do {
			printf("\nEnter the number of movies (Maximum of %d): ", MAX_MOVIES);
			success_value = scanf("%d", &num_movies);
			
			if (success_value != 1) {
				printf("Invalid input. Please enter the number of movies only.\n");
			} else if (num_movies <= 0) {
				printf("Invalid input. Please enter at least 1 number of movie.\n");
			} else if (num_movies > MAX_MOVIES)  {
				printf("Invalid input. Please enter a maximum of %d movies only.\n", MAX_MOVIES);
			}
			
			while (getchar() != '\n');

		} while (success_value != 1 || num_movies > MAX_MOVIES || num_movies <= 0);
		
		success_value = 0;

		do {
			printf("\nEnter the number of ratings per movie (Maximum of %d): ", MAX_RATINGS);
			success_value = scanf("%d", &num_ratings);
			
			if (success_value != 1) {
				printf("Invalid input. Please enter a number only.\n");
			} else if (num_ratings <= 0) {
				printf("Invalid input. Please enter at least 1 number.\n");
			} else if (num_ratings > MAX_RATINGS)  {
				printf("Invalid input. Please enter a maximum rating of %d only.\n", MAX_RATINGS);
			}
			
			while (getchar() != '\n');
			
		} while (success_value != 1 || num_ratings > MAX_RATINGS || num_ratings <= 0);

		
		movie_ratings = (int **)malloc(num_movies * sizeof(int *));
		for (int i = 0; i < num_movies; i++) {
			movie_ratings[i] = (int *)malloc(num_ratings * sizeof(int));
		}
		
		enter_ratings(movie_ratings, num_movies, num_ratings);
		display_ratings(movie_ratings, num_movies, num_ratings);
		
		// Free allocated memory
		for (int i = 0; i < num_movies; i++) {
			free(movie_ratings[i]);
		}
		free(movie_ratings);
		
		// Try the program again
		printf("\nWould you like to try the program again?\n");
		printf("(Press 1 to try again. Press any to exit.)\n");
		printf(">>> ");
		scanf("%d", &try_again);

	} while (try_again == 1);

	return 0;
}
