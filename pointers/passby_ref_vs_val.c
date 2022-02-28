/* This program will illustrate the difference between pass by reference and pass by value in C. Parameters passed to the function are called actual parameters, whil parameters recieved by the function and used inside the function are called formal parameters. 
 *
 * When you pass by value, the actual parameters are copied to the functions formal parameters. The variables passed in do not get modified. Passing by reference allows the function to modify the contents of what is stored at the memory address. */

#include <stdio.h>

void pass_by_val(int a);
void pass_by_ref(int *a);
int a = 10;

int main(void)
{
	pass_by_val(a);
	printf("Value after calling pass_by_val: %d\n", a);
	pass_by_ref(&a);
	printf("Value after calling pass_by_ref: %d\n", a);
	return 0;
}

void pass_by_val(int a)
{
	a += 5;
	printf("Value within function pass_by_val: %d\n", a);
}

void pass_by_ref(int *a)
{
	*a += 5;
	printf("Value within function pass_by_ref: %d\n", *a);
}
