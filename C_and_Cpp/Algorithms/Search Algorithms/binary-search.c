#include <stdio.h>

int binary_search(int *array, int size_of_array, int key_value)
{
    int middle_index;
    int left_index = 0; //Starting index
    int right_index = size_of_array - 1; //Last index
    
    while(left_index <= right_index)
    {
        //We need to find the median index i.e. middle index. 
        //Since C does not store any floating point in int datatype, 
        //We do not need the floor function from the math module  
        middle_index = (left_index + right_index ) / 2;
        if(array[middle_index] == key_value)
        {
            return middle_index;
        }
        else if(array[middle_index] < key_value)
        {
            left_index = middle_index + 1;
        }
        else //if array[middle_index] > key_value
        {
            right_index = middle_index - 1;
        }
        printf("\nMiddle Index: %d \n", middle_index);
    }
    // If key not found in the array
    printf("\nKeyNotFoundError: %d does not exist\n", key_value);
}

int main()
{
    int array[] = {1, 2 , 3 , 54, 78, 98};
    int size_of_array = sizeof(array) / sizeof(array[0]);
    int key_value = 9;
    int result_index = binary_search(array, size_of_array, key_value);
    printf("\nKey %d found at index %d\n", key_value, result_index);
    return 0;
}