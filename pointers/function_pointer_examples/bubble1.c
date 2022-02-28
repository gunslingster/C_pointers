/* This program will illustrate a bubble sort algorithm using pointers. 
 * This isn't the final version yet. Notice that bubble excepts pointers of type int.
 * Eventually we want to be able to pass void pointers to deal with many different data types. */

#include <stdio.h>

int arr[10] = {3,6,1,2,3,8,4,1,7,2};

//  Bubble is the sorting function, *p is a pointer to the array and N is the number of elements 
void bubble(int *p, int N);
// Compare takes two pointers to integers and just returns if the first is larger than the second
int compare(int *m, int *n);

int main(void)
{
    int i;
    for (i=0; i<10; i++)
    {
        printf("%d ", arr[i]);
    }
    bubble(&arr[0], 10);
    putchar('\n');
    printf("This is the sorted array\n");
    for (i=0; i<10; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void bubble(int *p, int N)
{
    int i, j ,t;
    for (i=N-1; i>=0; i--)
    {
        for (j=1; j<=i; j++)
        {
            // Keep in mind that p[j] is shorthand for *(p + j)
            // We have to use the reference & operator because the compare function accepts pointers as arguments.
            // p[j] is an integer and &p[j] returns the address where that integer is stored
            if (compare(&p[j-1], &p[j]))
            {
                // This is how a basic bubble sort works. It swaps elements pairwise.
                t = p[j-1];
                p[j-1] = p[j];
                p[j] = t;
            }
        }
    }
}

// Eventually we want the compare function to accept void pointers, then we can use casting to convert the pointer to the type we want
int compare(int *m, int *n)
{
    return (*m > *n);
}
