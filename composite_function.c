#include <stdio.h>
/* A small example of a composite function using pointers.
 * We pass multiple functions into another function to create a composite function.*/

int add(int n1, int n2);
int mul(int n1, int n2);
// We pass in two functions, which are pointers to functions of return type int
int add_mul(int n1, int n2, int n3, int (*fptr1) (int n1, int n2), int (*fptr2) (int n1, int n2));

int main()
{
    int res = add_mul(5, 6, 7, add, mul);
    printf("%d", res);
    return 0;
}

int add(int n1, int n2)
{
    return n1 + n2;
}

int mul(int n1, int n2)
{
    return n1 * n2;
}

int add_mul(int n1, int n2, int n3, int (*fptr1) (int n1, int n2), int (*fptr2) (int n1, int n2))
{
    // Printing out the address of the functions 
    // Keep in mind that in C *fptr = fptr
    // I only put the dereference operator for clarification
    printf("%p\n", *fptr1);
    printf("%p\n", *fptr2);
    int res1 = (*fptr1)(n1, n2);
    int res2 = (*fptr2)(res1, n3);
    return res2;
}
