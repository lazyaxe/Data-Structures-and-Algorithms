#include <stdio.h>

//tail recursion: recursive function at the end
void print_numbers(int lower_limit, int upper_limit)
{
    printf("\n");
    if(lower_limit==upper_limit)
    {
        return;
    }
    printf("%d ", lower_limit);
    print_numbers(lower_limit+1, upper_limit);
    printf("\n");
}

//mid-body recursion: recursive function is NOT at the end NOR at the start.
//Kind of like backwards execution...
void print_reverse(int lower_limit, int upper_limit)
{
    printf("\n");
    if(lower_limit==upper_limit)
    {
        return;
    }
    print_reverse(lower_limit+1, upper_limit);
    printf("%d ", lower_limit);
    printf("\n");
}

int main(void)
{
    print_numbers(1, 5);
    print_reverse(1, 5);
    return 0;
}