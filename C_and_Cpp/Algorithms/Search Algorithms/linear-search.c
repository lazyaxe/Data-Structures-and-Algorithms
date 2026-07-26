#include <stdio.h>

int linear_search(int *array, int size_of_array, int key_value)
{
    int i = 0;
    while (i < size_of_array)
    {
        if(array[i] == key_value)
        {
            return i;
        }
        i++;
    }
    // If key not found in the array
    printf("\nKeyNotFoundError: %d does not exist\n", key_value);
    
}

int main()
{
    int array[] = {1, 2 , 3 , 54, 78, 98};
    int size_of_array = sizeof(array) / sizeof(array[0]);
    int key_value = 98;
    int result_index = linear_search(array, size_of_array, key_value);
    printf("\nKey %d found at index %d\n", key_value, result_index);
    return 0;
}