#include <stdio.h>
#include <math.h>

int factorial_by_iteration(int n)
{
    int total = 1;
    if (n == 0 || n == 1)
    {
        return total;
    }
    if(n<0)
    {
        printf("\nNegative numbers are invalid\n");
        return 1;
    }
    for(int i = n; i > 0; i--)
    {
        total *= i;
    }
    return total;
}

int factorial_by_recursion(int n)
{
    if(n < 0)
    {
        printf("\nNegative numbers are invalid\n");
        return 1;
    }
    if(n == 1)
    {
        return 1;
    }
    return n * factorial_by_recursion(n - 1);
}


int main()
{
    int test_number = 10;
    printf("%d\n", factorial_by_iteration(test_number));
    printf("%d", factorial_by_recursion(test_number));
    return 0;
}