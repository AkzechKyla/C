/* 1. Write a program in C to count the total number of duplicate elements in an array. */

    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[j] == arr[i]) {
                dupes++;
            }
        }
    }

/* 2. Write a program in C to print all unique elements in an array. */

    printf("\nThe unique elements found in the array are: \n");
    for (i = 0; i < length; i++) {
        count = 0;
        for (j = 0 ; j < length; j++) {
            if (i != j) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
        }

        if (count == 0) {
            printf("%d ", arr[i]);
        }
    }

/* 3. Write a program in C to merge two arrays of the same size sorted
in descending order. */

    length3 = length1 + length2;

    // insert in 3rd array
    for (i = 0; i < length1; i++) {
        arr3[i] = arr1[i];
    }

    for (j = 0; j < length2; j++) {
        arr3[i] = arr2[j];
        i++;
    }

    // sort in descending order
    for (i = 0; i < length3; i++) {
        for (k = 0; k < length3 - 1; k++) {
            if (arr3[k] <= arr3[k + 1]) {
                j = arr3[k + 1];
                arr3[k + 1] = arr3[k];
                arr3[k] = j;
            }
        }
    }

/* 4. Write a program in C to count the frequency of each element of an array. */

    for (i = 0; i < length; i++) {
        count = 1;
        for (j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0;
            }
        }

        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

/* 5. Write a program in C to find the maximum and minimum elements in an array. */

    max = arr[0];
    min = arr[0];

    for (i = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }
    }

/* 6. Write a program in C to separate odd and even integers into separate arrays. */

    // user input loop
        if (input % 2 == 0) {
            even_array[i] = input;
            odd_array[i] = -1;
        } else {
            even_array[i] = -1;
            odd_array[i] = input;
        }

    printf("\nThe Even elements are : \n");
    for (int i = 0; i < length; i++) {
        int value = even_array[i];

        if (value >= 0) {
            printf("%d ", value);
        }
    }

    printf("\nThe Odd elements are : \n");
    for (int i = 0; i < length; i++) {
        int value = odd_array[i];

        if (value >= 0) {
            printf("%d ", value);
        }
    }

/* 7. Write a program in C to find the second largest element in an array. */

    largest = 0;
    for (i = 0; i < length; i++) {
        if (largest < arr[i]) {
            largest = arr[i];
            j = i;
        }
    }

    largest2 = 0;
    for (i = 0; i < length; i++) {
        if (i == j) {
            i++; // ignore largest element
            i--;
        } else {
            if (largest2 < arr[i]) {
                largest2 = arr[i];
            }
        }
    }

/* 8. Write a program in C to convert a decimal number to a binary number using the function. */

void converter(int decimal)
{
    if (decimal > 0)
	{
        converter(decimal / 2);
        printf("%d", decimal % 2);
    }
}

/* 9. Write a program in C to print all perfect numbers in a given range using the function. */

int is_perfect(int number) {
    int sum = 0;

    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    if (sum == number) return 1;
    return 0;
}
    // main
    printf("The perfect numbers between %d to %d are :\n", lowest, highest);
    for (int i = lowest; i <= highest; i++) {
        if (is_perfect(i)) {
            printf("%d   ", i);
        }
    }

/* 10. Write a program in C to make such a pattern like a
right angle triangle with a number which will repeat a number in a row.*/

    int size = 4;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d", i + 1);
        }
        printf("\n");
    }

/* 11. Write a program in C to make such a pattern like a right angle triangle
with the number increased by 1.*/

    int size = 4;
    int counter = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d ", counter);
            counter++;
        }
        printf("\n");
    }

/* 12. Write a program in C to make a pyramid pattern with numbers increased by 1. */

    int size = 4;
    int counter = 1;

    for (int i = 0; i < size; i++) {
        int paddingSize = size / 2 - i + 1;

        for (int p = 0; p < paddingSize; p++) {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++) {
            printf("%d ", counter);
            counter++;
        }
        printf("\n");
    }

/* 13. Write a program in C to print Floyd's Triangle. */

    int size = 5;  // this time, the size is 5
    int value = 1;  // number to print

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d", value);


            if (value == 0) value = 1;
            else if (value == 1) value = 0;
        }

        if (i % 2 == 1) {
            if (value == 0) value = 1;
            else if (value == 1) value = 0;
        }

/* 14. Write a program in C to find the number and sum of all integers between
100 and 200 which are divisible by 9. */

    for (int i = 100; i <= 200; i++) {
        if (i % 9 == 0) {
            printf("%d ", i);
            sum += i;
        }
    }

/* 15. Write a C program to convert a binary number into a decimal number
without using array, function and while loop. */

    int input_binary;
    int digit = 0;
    int position = 1;
    int decimal = 0;
    int i = 1;

    int temp = input_binary;
    for (int j = temp; j > 0; j = j/10) {
        digit = j % 10;

        if (i == 1) {
            position = position * 1;
        } else {
            position = position * 2;
        }

        decimal = decimal + (digit * position);
        i++;
    }

/* 16. Write a program in C to convert a decimal number into octal without using an array. */

    int decimalNum, quotient, octalNum = 0, temp, position = 1;

    quotient = decimalNum;

    while (quotient != 0) {
        temp = quotient % 8;
        octalNum += temp * position;
        quotient /= 8;
        position *= 10;
    }

/* 17. Write a C program to convert an octal number to a decimal without using an array. */

    int octal, decimal = 0, base = 1;

    int temp = octal;
    while (temp > 0) {
        int digit = temp % 10;
        decimal += digit * base;
        base *= 8;
        temp /= 10;
    }

/* 18. Write a program in C to find the largest element using Dynamic Memory Allocation. */

  int n;
  double *data;
  printf("Enter the total number of elements: ");
  scanf("%d", &n);

  data = (double *)calloc(n, sizeof(double));
  if (data == NULL) {
    printf("Error!!! memory not allocated.");
    exit(0);
  }

  for (int i = 0; i < n; ++i) {
    printf("Enter number %d: ", i + 1);
    scanf("%lf", data + i);
  }

  for (int i = 1; i < n; ++i) {
    if (*data < *(data + i)) {
      *data = *(data + i);
    }
  }

  free(data);

/* 19. Write a program in C to sort an array using a pointer. */

void sortArray(int *arr, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(arr + j) < *(arr + i)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

/* 20. Write a program in C to compute the sum of all elements in an array using pointers. */

    int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

/* 21. Write a program in C to count the number of vowels and consonants in a string using a pointer. */

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

/* 22. Write a program in C to compute the sum of all elements in an array using pointers. */
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

/* 23. Write a program in C to print the elements of an array in reverse order using pointer. */

    //For loop to scan elements
    for (i = 1; i <= num; i++)
    {
        printf("elements - %d : ", i);
        scanf("%d",  (ptr + i));
    }

    //For loop to reverse the elements
    for (i = num; i > 0; i--)
    {
        printf("elements - %d : ", i);
        printf("%d\n", *(ptr + i));
    }

/* 24. Write a program in C to print a string in reverse using a pointer. */

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

/* 25. Write a C program to get the indices of two numbers in a given array of integers.
This will enable you to get the sum of two numbers equal to a specific target. */

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (orig_array[i] + orig_array[j] == target) {
                printf("%d %d", i, j);
                break;
            }
        }
    }
