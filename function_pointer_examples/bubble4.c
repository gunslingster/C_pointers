#include <stdio.h>
#include <string.h>

#define MAX_BUF 256

long arr[10] = {3,6,1,2,3,8,4,1,7,2};
char arr2[5][20] = {"Paul Smith", "Tom Abrahams", "Jessie James", "Frank Dawson", "Ally Connor"};

// This time bubble will also accept a function pointer that points to the comparison function
void bubble(void *p, size_t width, int N, int (*fptr) (const void *m, const void *n));
int compare_string(const void *m, const void *n);
int compare_long(const void *m, const void *n);

int main(void)
{
	int i;
	for (i=0; i<10; i++)
	{
		printf("%ld ", arr[i]);
	}
	putchar('\n');
	for (i=0; i<5; i++)
	{
		printf("%s\n", arr2[i]);
	}
	bubble(arr, sizeof(long), 10, compare_long);
	bubble(arr2, 20, 5, compare_string);
	putchar('\n');
	for (i=0; i<10; i++)
	{
		printf("%ld ", arr[i]);
	}
	putchar('\n');
	for (i=0; i<5; i++)
	{
		printf("%s\n", arr2[i]);
	}
	putchar('\n');
	return 0;
}

void bubble(void *p, size_t width, int N, int (*fptr) (const void *, const void *))
{
	int i, j, k;
	unsigned char buf[MAX_BUF];
	unsigned char *bp = p;
	for (i=N-1; i>=0; i--)
	{
		for (j=1; j<=i; j++)
		{
			k = fptr((void *)(bp + width*(j-1)), (void *)(bp + j*width));
			if (k > 0)
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

// The Use of void pointers allows us to cast the type of the pointer inside the function 
int compare_string(const void *m, const void *n)
{
	char *m1 = (char *)m;
	char *n1 = (char *)n;
	return (strcmp(m1,n1));
}

int compare_long (const void *m, const void *n)
{
	long *m1, *n1;
	m1 = (long *)m;
	n1 = (long *)n;
	return (*m1 > *n1);
}
