#include <stdio.h>
#define ROWS 5
#define COLS 10

// Initialize a 2d array
// Keep in mind that when we reference multi, it is actually referencing  the address of the first element
// Multi points to the address of the first array
int multi[ROWS][COLS];

int main(void)
{
	// Set all the entries to row*col
	for (int row=0; row<ROWS; row++)
	{
		for (int col=0; col<COLS; col++)
		{
			multi[row][col] = row*col;
		}
	}
	for (int row=0; row<ROWS; row++)
	{
		for (int col=0; col<COLS; col++)
		{
			// Print the address of the first element of the current ro
			printf("%p ", (multi + row));
			// Print the address of the element itself
			printf("%p ", ((multi + row) + col));
			// Print the element
			printf("%d ", multi[row][col]);
			// Alternate way of retrieveing the value of the element using the dereference operator
			printf("%d\n", *(*(multi + row) + col));
		}
	}
	printf("\n");
	return 0;
}
