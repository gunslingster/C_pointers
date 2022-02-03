#include <stdio.h>
#include <string.h>

// A struct with 4 attributes
struct tag
{
    char lname[20];
    char fname[20];
    int age;
    float rate;
};

struct tag my_struct;
// Function prototype
void show_name(struct tag *p);

int main(void)
{
    // Initialize a pointer to the global struct
    struct tag *st_ptr;
    // Set the pointer equal to the address of my_struct
    st_ptr = &my_struct;
    strcpy(my_struct.lname, "Jones");
    strcpy(my_struct.fname, "Jimmy");
    my_struct.age = 63;
    // Here are passing in st_ptr which points to my_struct
    show_name(st_ptr);
    return 0;
}

void show_name(struct tag *p)
{
    // The arrow operator is really just syntactic sugar
    // We can just as well do (*p).fname
    printf("%s\n", p->fname);
    printf("%s\n", p->lname);
    printf("%d\n", p->age);
}
