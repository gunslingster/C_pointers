/* An example of malloc and how it allocates a contiguous block of memory*/

#include <stdlib.h>
#include <stdio.h>

void malloc_example(void);

int main(void)
{
    malloc_example();
    return 0;
}

void malloc_example(void)
{
    int *arr = (int*) malloc(20 * sizeof(int));
    for(int i=0; i<20; i++)
    {
        *(arr + i) = i * 2;
        printf("Location in memory: %p  Value stored: %d\n", (arr+i), *(arr+i));
    }
    free(arr);
}

