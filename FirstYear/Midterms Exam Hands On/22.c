/* Write a program in C to compute the sum of all elements in an array using pointers. */

#include <stdio.h>

int main(int argc, const char * argv[])
{
	int arr[100];
	int *ptr;
	int elements, i;

	ptr = arr;

	printf("Input the number of elements to store in the array: ");
	scanf("%d",
		&elements);

	printf("Input %d number of elements in the array:\n", elements);

	for(i = 0; i < elements; i++)
	{
		printf("Element - %d: ", i + 1);
		scanf("%d",
			(ptr + i)); //without asterisk, para ma-access address
	}

	int sum = 0;

	for(i = 0; i < elements; i++)
	{
		sum += *(ptr + i); //with asterisk, para ma-access value
	}

	printf("The sum of array is: %d", sum);

	return 0;
}
