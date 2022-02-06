#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int x_dim = 15;
int y_dim = 7;
int z_dim = 3;

int main(void)
{
    int *space;
    int ***arr3d;
    int x, y, z;

    // Allocate a contiguous block of memory for the array
    space = malloc(x_dim * y_dim * z_dim * sizeof(int));

    // Allocate space for an array of pointers to pointers 
    arr3d = malloc(z_dim * sizeof(int **));

    // Point each element to a row of pointers
    for (z=0; z<z_dim; z++)
    {
        arr3d[z] = malloc(y_dim * sizeof(int *));

        for (y=0; y<y_dim; y++)
        {
            // Keep in mind that space is an integer pointer
            // This means that arr[z][y] also has type of int pointer
            // We may visualize this as a 3d array, but in reality it is an array of 2d arrays
            // In memory, this is all one contiguous block
            // Each element arr[z][y] is going to point to a new row in a 2d array
            // z * (x_dim + y_dim) gives us the location of which 2d array we are on
            // y * x_dim gives us the location of the specific row in that 2d array
            arr3d[z][y] = space + (z * (x_dim + y_dim) + y * x_dim);
        }
    }

    // Now we are just assigning a value to the elements in the array
    for (z=0; z<z_dim; z++)
    {
        for (y=0; y<y_dim; y++)
        {
            for (x=0; x<x_dim; x++)
            {
                arr3d[z][y][x] = x+y+z;
            }
        }
    }
    // Print out the values along with the locations in memory
    for (z=0; z<z_dim; z++)
    {
        printf("\n\n");
        printf("Location of 2d array #%d in memory is: %p ", z, *arr3d[z]);
        for (y=0; y<y_dim; y++)
        {
            printf("\n");
            printf("Location of this row in memory is: %p ", arr3d[z][y]);
            for (x=0; x<x_dim; x++)
            {
                printf("%d ", *(*(*(arr3d + z) + y) + x)); 
            }
        }
    }
    printf("\n");
}
