#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int size_of_array)
{
    int i = 0;
    int j = 0;
    for (int i = 0; i < size_of_array - 1; i++)
    {
        bool is_swapped = false;
        for (int j = 0; j < size_of_array - i -1; j++)
        {
            if(array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                is_swapped = true;
            }
        }
        //Optimization Tweak: Exit if no swap was performed in first try i.e. all the elements are sorted/correct order.
        if (is_swapped == false) break;
    }
}

int main()
{
    int array[] = {7, 6, 5, 4, 3, 2, 1, 987, 55, 21, 65};
    int array_size = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, array_size);
    int i = 0;
    while(i < array_size)
    {
        printf("%d ", array[i]);
        i++;
    }
    return 0;
}