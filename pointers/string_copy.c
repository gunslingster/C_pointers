#include <stdio.h>

// Keep in mind there are no strings in C
// Strings are represented by char arrays
// Start out by declaring 2 char arrays, one will contain a random string, the other will be empty
char string1[80] = "A random string";
char string2[80];

int main(void)
{
	// Initialize two pointers, one for each of the global arrays
	char *pA;
	char *pB;

	// Display contents of string1 on the screen
	// Keep in mind that puts accepts a pointer. When you pass in string1, it is equivalent to passing in &string1[0]
	puts(string1);
	puts(&string1[0]);
	// Set the value of pA to string1[0]
	// Keep in mind that now if we modify the contents of any address that pA is pointing to, it will also modify string1
	pA = string1;
	// For instance, *pA = '1' will replace the first character in with 1
	puts(pA);
	// Set the value of pB to string2[0]
	pB = string2;
	// This is where it gets a little tricky. This is the code block that copies the contents of string1 into string2. 
	// We increment both pointers with an assignment statement inbetween.
	// The final effect of this is that we are copying characters one by one into the memory locations for string2
	while (*pA != '\0')
	{
		*pB++ = *pA++;
	}

	// The \0 is a special null character. It lets the compiler know that this is the end of the string
	*pB = '\0';
	puts(string2);
	return 0;
	// The output will be the same string printed 4 times. 
}
