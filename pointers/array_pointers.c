#include <stdio.h>

// Initialize an array with some random elements
int arr[] = {23, 41, 109, -5, 2, 7};
// Initialize a pointer for an integer 
int *ptr;

int main(void)
{
	// Set the value of the pointer to the locaiton in memory of the first element in the array
	ptr = &arr[0];
	printf("\n\n");
	for (int i=0; i<6; i++)
	{
		// Print the element of the array
		printf("arr[%d] = %d	", i, arr[i]);
		// Do the same thing using pointers
		// This is an example of pointer arithmetic
		// When you add a number to a pointer, it is actually adding the designated amount of bytes
		// If in integer is 4 bytes, then (ptr + 4) will actually increment the pointer by 16 bytes
		printf("ptr + %d = %d\n", i, *(ptr + i));
	}
	return 0;
}

