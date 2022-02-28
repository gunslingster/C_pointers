#include <stdio.h>
#include <stdlib.h>

/* Here we will be showing how to create a dynamic 2d array.
 * The nrows and ncols are assumed to be evaluated at runtime*/

int main(void)
{
	// Both nrows and ncols could be evaluated or read at run time
	int nrows = 5;
	int ncols = 10;
	int row;
	// Intialize a pointer to an integer pointer
	int **rowptr;
	// malloc returns a void pointer to the starting address of the reserved space. It will return null if no space is available
	// rowptr poinrt to the first element of an array or pointers of type int
	rowptr = malloc(nrows * sizeof(int *));
	printf("Start of the array: %p\n", rowptr);
	if (rowptr == NULL)
	{
		puts("\nFailure to allocate space.\n");
		exit(0);
	}

	// Here we us dynamic allocation again. Now we allocate space for the actual integers.
	for (row=0; row<nrows; row++)
	{
		// Once again keep in mind that malloc returns a pointer. rowptr[row] will point to the address of the first element of an array of integers
		rowptr[row] = malloc(ncols * sizeof(int));
		printf("Start of row %d: %p\n",row, rowptr[row]);
	
		if (rowptr[row] == NULL)
		{
			printf("\nFailure to allocate space.\n");
			exit(0);
		}
		// If it's not null when can assignt the element to some value
	
	}
	for (int row=0; row<nrows; row++)
	{
		for (int col=0; col<ncols; col++)
		{
			// This is equivalent to using rowptr[row][col]
			*(*(rowptr + row) + col) = row + col;
			printf("arr[%d][%d] = %d\n", row, col, rowptr[row][col]);
		}
	}
}
