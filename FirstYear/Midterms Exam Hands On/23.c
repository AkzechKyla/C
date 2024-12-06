/* Write a program in C to print the elements of an array in reverse order using pointer. */

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int num, arr[15];
    int i, *ptr;

    ptr = &arr[0];

    printf("Input the number of elements to store in the array (max 15): ");
    scanf("%d", &num);
    printf("\nInput %d number of elements in the array:\n", num);

    //For loop to scan elements
    for (i = 1; i <= num; i++)
    {
        printf("elements - %d : ", i);
        scanf("%d",  (ptr + i));
    }

    printf("\nThe elements of array in reverse order are: \n");

    //For loop to reverse the elements
    for (i = num; i > 0; i--)
    {
        printf("elements - %d : ", i);
        printf("%d\n", *(ptr + i));
    }

    return 0;
}
