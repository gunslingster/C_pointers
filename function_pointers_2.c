/* This time we are implementing the bubble sort again, but this time 
 * we pass void pointers to our compare function. This enables to cast
 * and compare any data type. The rest of the code is the same. */
#include <stdio.h>

int arr[10] = {3,6,1,2,3,8,4,1,7,2};

void bubble(int *p, int N);
// Notice now we are passing in void pointers instead of int pointers
int compare(void *m, void *n);

int main(void)
{
	int i;
	for (i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	bubble(arr, 10);
	putchar('\n');
	for (i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
	return 0;
}

void bubble(int *p, int N)
{
	int i, j, t;
	for (i=N-1; i>=0; i--)
	{
		for (j=1; j<=i; j++)
		{
			// We have to cast the pointers to void to pass them into the compare function.
			if (compare((void *)&p[j-1], (void *)&p[j]))
			{
				t = p[j-1];
				p[j-1] = p[j];
				p[j] = t;
			}
		}
	}
}

// This is the primary difference from the first example. By passing in void pointers it allows us to compare any data type.
int compare (void *m, void *n)
{
	int *m1, *n1;
	// We have to cast to the data type we want to compare
	// This way we don't have to rewrite the sort function, but simply change the compare function
	m1 = (int *)m;
	n1 = (int *)n;
	// We still have to dereference since m1 and n1 are pointers
	return (*m1 > *n1);
}
