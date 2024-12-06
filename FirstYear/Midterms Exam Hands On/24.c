/* Write a program in C to print a string in reverse using a pointer. */
#include <stdio.h>

int main( int argc, const char * argv[])
{
    char arr[80];
    char rev_arr[80];
    char *ptr = arr;
    char *rev_ptr = rev_arr;
    int i = -1;

    printf("\nPointer : Print a string in reverse order : ");
    scanf("%s", arr);

    while(*ptr)
    {
        *ptr++;
        i++;
    }

    while (i >= 0)
    {
        ptr--;
        *rev_ptr = *ptr;
        rev_ptr++;
        --i;
    }

    *rev_ptr = '\0';

    printf("The reverse of the string is  : %s\n\n", rev_arr);

    return 0;
}
