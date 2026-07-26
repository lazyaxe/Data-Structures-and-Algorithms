/*
Find the sum of all the elements in an integer array/list using recursion
*/

#include <stdio.h>

//1. Addition of array elements by iteration/loop 
int add_array_by_iteration(int *array_ptr, int size_of_array)
{
    int sum = 0;
    for(int i = 0; i < size_of_array; i++)
    {
        sum += *(array_ptr + i);//equivalent to array_ptr[i]
    } 
    return sum;
}

//2. Addition of array elements by recursion(tail recursion):
int add_array_by_recursion(int *array_ptr, int size_of_array)
{
    if(size_of_array == 0)
    {
        return 0;
    }
    return *array_ptr + add_array_by_recursion(array_ptr + 1, size_of_array - 1);
}

int main()
{
    int test_array[5] = {1, 2, 3, 4, 10};
    /*printf("%d", add_array_by_iteration(test_array,  sizeof(test_array) / sizeof(test_array[0])));
    */
   printf("%d ", add_array_by_iteration(test_array, sizeof(test_array) / sizeof(test_array[0])));
   return 0;
}