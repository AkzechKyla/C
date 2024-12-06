/* Write a program in C to count the number of vowels and consonants in a string using a pointer. */

#include <stdio.h>

int main(int argc, const char * argv[])
{
	int countv = 0, countc = 0, i = 0;
	char *ptr;
	char str[80];
	ptr = str;

	printf("Input a string: ");
	fgets(str, sizeof(str), stdin);

	while(*(ptr + i) != '\0')
	{
		if(*(ptr + i) == 'A' || *(ptr + i) == 'a' || *(ptr + i) == 'I' || *(ptr + i) == 'i'|| *(ptr + i) == 'U'
		|| *(ptr + i) == 'u' || *(ptr + i) == 'E' || *(ptr + i) == 'e' || *(ptr + i) == 'O' || *(ptr + i) == 'o')
		{
			countv++;
		}
		else
		{
			countc++;
		}

		i++;
	}

	printf("Number of vowels: %d\n", countv);
	printf("Number of consonants: %d", countc - 1); //with countc - 1 kasi sa "else", cin count din si null as "consonant", kaya magm-minus 1 tayo

	return 0;
}
