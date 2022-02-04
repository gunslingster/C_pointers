#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **rptr;     // A pointer to an array of pointers which point to some integer arrays
    int *aptr;      // A pointer that points to the beginning of the 2d array
    int *testptr;   // Will use this pointer to increment through the array to prove it's contiguous 
    int k;
    int nrows = 5;
    int ncols = 5;
    int row, col;

    // Now we are going to dynamically allocate memory for the 2d array
    aptr = malloc(nrows * ncols * sizeof(int));
    if (aptr == NULL)
    {
        puts("\nFailure to allocate memory for the array");
        exit(0);
    }
    // Now we dynamically allocate memory for the array of pointers. Each will point to a specific row in the 2d array.
    rptr = malloc(nrows * sizeof(int *));
    if (rptr == NULL)
    {
        puts("\nFailure to allocate memory for the pointers");
        exit(0);
    }
    // Now comes the interesting part. We are going to assign each pointer to a specific row.
    // Iterate through the rows
    for (k=0; k<nrows; k++)
    {
        rptr[k] = aptr + (k * ncols);
    }
    for (row = 0; row < nrows; row++)
    {
        printf("\n%d %p", row, rptr[row]);
        if (row > 0)
        {
            printf("        %d", (rptr[row] - rptr[row-1]));
        }
    }
    putchar('\n');

    for (row=0; row<nrows; row++)
    {
        for (col=0; col<ncols; col++)
        {
            // the code belowe is the same as rptr[row][col] 
            // When you dereference a double pointer you get another pointer 
            *(*(rptr + row) + col) = row + col;
            printf("%d ", rptr[row][col]);
        }
        putchar('\n');
    }
    // Now to prove that the memory is a contiguous block
    // aptr points to the first element of the 2d array
    // This code is going to print out elements 1 by 1
    // When we increment, we are moving to the next space in memory where the integer is held
    testptr = aptr;
    for (row=0; row<nrows; row++)
    {
        for (col=0; col<ncols; col++)
        {
            printf("%d ", *(testptr++));
        }
        putchar('\n');
    }
    return 0;

}
