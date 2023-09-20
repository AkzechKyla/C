#include <stdio.h>
#include <string.h>

#define SERIES_FILE "series.txt"
#define MAX_SERIES 100

FILE *file_ptr;

int series_count = 0;
char series[MAX_SERIES][100];
char line[100];

int is_file_exist() {
	file_ptr = fopen(SERIES_FILE, "r");

	if (file_ptr == NULL) {
		printf("\nFAILED TO OPEN THE FILE.\n");
		fclose(file_ptr);
		return 0;
	}

	fclose(file_ptr);
	return 1;
}

void read_file() {
	file_ptr = fopen(SERIES_FILE, "r");

	while (fgets(line, sizeof(line), file_ptr)) {
		// Remove the newline character at the end of the line
		line[strcspn(line, "\n")] = '\0';

		// Copy the series name to the array
		strcpy(series[series_count], line);
		series_count++;

		// Ensure we don't exceed the array size
		if (series_count >= MAX_SERIES) {
			printf("Maximum number of series reached. Some series may have been truncated.\n");
			break;
		}
	}

	fclose(file_ptr);
}

int main() {
	if (!is_file_exist()) return 1;
	read_file();
	
	long long int uid;
	char formattedCodes[100][100];
	char edition[10];
	char tag[20];
	
	// tc 637931483218051102 s=series
	
	printf("\nTOFU CODE HUNTING FORMATTER\n");
	printf("Enter the id of the user: ");
	scanf("%lld", &uid);
	
	printf("\n**CARD EDITIONS: 1, W21, W22, S22, S23, SP22, SP22, SP23, F22, ANY (except for 1s)\n");
	printf("Enter the card edition: ");
	scanf("%s", edition);
	
	printf("\nDo they have a specific tag? If yes, enter the tag name: ");
	scanf("%s", tag);
	
	if (strcmp(tag, "no") == 0) {
		for (int j = 0; j < series_count; j++) {
			if (strcmp(edition, "any") == 0) {
				printf("tc %lld s=%s e>1 o=c\n", uid, series[j]);
			} else {
				printf("tc %lld s=%s e=%s o=c\n", uid, series[j], edition);
			}
		}
	} else {
		for (int j = 0; j < series_count; j++) {
			if (strcmp(edition, "any") == 0) {
				printf("tc %lld s=%s e>1 t=%s o=c\n", uid, series[j], tag);
			} else {
				printf("tc %lld s=%s e=%s t=%s o=c\n", uid, series[j], edition, tag);
			}
		}
	}

	
	return 0;
}
