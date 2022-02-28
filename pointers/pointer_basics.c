#include <stdio.h>

int j, k;	// Initialize two integer variables
int *ptr;	// Declare a pointer of type int
		// Depending on the type, may occypy 2 bytes, 4 bytes, etc.

int main(void)
{
	j = 1;
	k = 2;
	ptr = &k;	// The ampersand is to reference the address of k
			// The address is some location in memory specified by a hexadecimal number
	printf("\n");
	// Print j and the address it is located
	printf("j has the value %d and is stored at %p\n", j , &j);
	// Print k and the address it is located
	printf("k has the value %d and is stored at %p\n", k, &k);
	// Print ptr, which is an address, it will be the same as the address of k
	printf("ptr has the value %p and is stored at %p\n", ptr, &ptr);
	// Since pointer is the address of k, when you dereference it, it will have the same value as k, which is 2
	printf("The value of the integer pointed to by ptr is %d\n", *ptr);
	return 0;
}
