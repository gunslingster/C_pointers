/* In this example we are going to modify our bubble and compare functions. 
 * We want bubble to eventually be able to sort independent of the type of data passed in.
 * The primary modification will be the removal of the variable t in our bubble function.
 * Instead we will use a buffer of specified length to serve as the temporary storage.
 * We also now need to modify our bubbble function to accept a void pointer. By passing in a void pointer
 * we lose some information. We need an extra argument to tell the compiler the size of the data we are sorting. */

#include <stdio.h>
#include <string.h>

long arr[10] = {3,6,1,2,3,8,4,1,7,2};

// We have to modify bubble and add an extra argument width. Width is the size of the data we are sorting.
// In this specific example we will be using an array of longs.
void bubble(void *p, size_t width, int N);
int compare(void *m, void *n);

int main(void)
{
	int i;
	for (i=0; i<10; i++)
	{
		printf("%ld ", arr[i]);
	}
	bubble(arr, sizeof(long), 10);
	putchar('\n');
	for (i=0; i<10; i++)
	{
		printf("%ld ", arr[i]);
	}
	putchar('\n');
	return 0;
}

void bubble(void *p, size_t width, int N)
{
	int i, j;
	// The size of the buffer will vary depending on the data we are sorting
	// In this case, a long is 8 bytes, and a char is 1 byte, so we need a buffer of size 8
	unsigned char buf[8];
	// A pointer to the first element of the array
	unsigned char *bp = p;
	print("%p\n", bp);
	print("%p\n", p);
	for (i=N-1; i>=0; i--)
	{
		for (j=1; j<=i; j++)
		{
			// This is where is gets a little complicated
			// bp is a pointer of type char to the array
			// When we do pointer arithmetic, we have to multiply by width, which in this case is 8, the size of a long
			if (compare((void *)(bp + width*(j-1)), (void *)(bp + j*width)))
			{
				// Each one of the following lines is equivalent to a line in the previous program
				// t = arr[j-1]
				memcpy(buf, bp + width * (j-1), width);
				// arr[j-1] = arr[j]
				memcpy(bp + width * (j-1), bp + width * j, width);
				// arr[j] = t;
				memcpy(bp + width*j, buf, width);
			}
		}
	}
}

int compare (void *m, void *n)
{
	long *m1, *n1;
	// We have to cast to the data type we want to compare
	m1 = (long *)m;
	n1 = (long *)n;
	// We still have to dereference since m1 and n1 are pointers
	return (*m1 > *n1);
}
